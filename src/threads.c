#include "../inc/so_long"

void *is_dead(void *data)
{
    t_philo *ph;

    ph = (t_philo *)data;
    ft_usleep(ph->pa->time_to_die);
    pthread_mutex_lock(&ph->pa->time_eat_mutex);
    pthread_mutex_lock(&ph->pa->finish_mutex);
    if(!check_death(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) \ >= 
            (long)(ph->pa->time_to_die)))
    {
        pthread_mutex_unlock(&ph->pa->time_eat_mutex);
        pthread_mutex_unlock(&ph->pa->finish_mutex);
        pthread_mutex_lock(&ph->pa->write_mutex);
        print_status(RED"died\n"CLEAR, ph);
        pthread_mutex_unlock(&ph->pa->write_mutex);
        check_death(ph, 1);
    }
    pthread_mutex_unlock(&ph->pa->time_eat_mutex);
    pthread_mutex_unlock(&ph->pa->finish_mutex);
    return (NULL);
}


void *thread(void *data)
{
    t_philo *ph;
    ph = (t_philo *)data;
        ft_usleep(ph->pa->time_to_eat / 10);
    while (!check_death(ph, 0))
    {
        pthread_create(&ph->thread_death_id, NULL, is_dead, data);
        simulation(ph);
        if((int)++ph->nb_philo_ate == ph->pa->meals)
        {
            pthread_mutex_lock(&ph->pa->finish_mutex);
            ph->finish = 1;
            ph->pa->number_philo_ate++;
            if(ph->pa->number_philos_ate == ph->pa->philos)
            {
                pthread_mutex_unlock(&ph->pa->finish_mutex);
                check_death(ph, 2);
            }
            pthread_mutex_unlock(&ph->pa->finish_mutex);
            return (NULL);
        }
    }
    pthread_join(ph->thread_death_id, NULL);
    return (NULL);   
}

int threading(t_p *p)
{
    int i;
    i = 0;
    while (i < p->a.philos)
    {
        p->ph[i].pa = &p->a;
        if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i] != 0))
            return (ft_exit("Pthread did not retunr 0\n"));
        i++;
    }
    return (1);
}
