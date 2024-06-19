#include "../inc/philo.h"

/*this function checks if the philospher died due too starvation*/
int check_death(t_philo *ph, int i)
{
    pthread_mutex_lock(&ph->pa->dead_mutex);
    if (i)
        ph->pa->stop_t = i;
    if (ph->pa->stop_t)
    {
        pthread_mutex_unlock(&ph->pa->dead_mutex);
        return (1);
    } 
    pthread_mutex_unlock(&ph->pa->dead_mutex);
    return (0);
}

void stop(t_p *p)
{
    int i = -1;
    while (!check_death(p->ph, 0))
        ft_usleep(1);
    
    while (++i < p->a.philos)
    {
        pthread_mutex_destroy(&p->ph[i].left_fork);
    }
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.philos)
	{
		pthread_mutex_destroy(&p->ph[i].left_fork);
	}
    if (p->a.stop_t == 2)
        printf(GREEN"Each philosopher ate %d times\n"CLEAR, p->a.meals);
    free(p->ph); 
}


int ft_exit(char *str)
{
    printf(RED"Error :"CLEAR);
    printf(RED"%s"CLEAR, str);
    printf(RED"./philo [philo] [die] [eat] [sleep] [meals] \n"CLEAR);
    return (0); 
}