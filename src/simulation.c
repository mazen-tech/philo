#include "../inc/philo.h"



void print_status(char *str, t_philo *ph)
{
    long int time;

    time = -1;//inisializing time first to -1 wont require any error checking
    time = actual_time() - ph->pa->start_t;

    if(time >= 0 && time <= 2147483647 && !check_death(ph, 0))
    {
        printf(BOLD"%ld ms "CLEAR, time);//here we printing the time in miliseconds
        printf("philo %d %s", ph->id, str);
    }
}


   
void sleep_and_think(t_philo *ph)
{
    pthread_mutex_lock(&ph->pa->write_mutex);//look the mutex for writing
    print_status(BLUE"is sleaping\n"CLEAR, ph);

    pthread_mutex_unlock(&ph->pa->write_mutex);
    ft_usleep(ph->pa->time_to_sleep);

    pthread_mutex_lock(&ph->pa->write_mutex);
    print_status(YELLOW"is thinking\n"CLEAR, ph);

    pthread_mutex_unlock(&ph->pa->write_mutex);
}


void simulation(t_philo *ph)
{
    pthread_mutex_lock(&ph->left_fork);
    pthread_mutex_lock(&ph->pa->write_mutex);
    print_status(GREEN"has taken a fork\n"CLEAR, ph);
    pthread_mutex_unlock(&ph->pa->write_mutex);

    if(!ph->right_fork)
    {
        ft_usleep(ph->pa->time_to_die * 2);
        return ;
    }
    pthread_mutex_lock(ph->right_fork);
    pthread_mutex_lock(&ph->pa->write_mutex);
    print_status(GREEN"has taken a fork\n"CLEAR, ph);
    pthread_mutex_unlock(&ph->pa->write_mutex);
    pthread_mutex_lock(&ph->pa->write_mutex);
    print_status(PURPLE"is eating\n"CLEAR, ph);
    pthread_mutex_lock(&ph->pa->time_eat_mutex);
    ph->ms_eat = actual_time();
    pthread_mutex_unlock(&ph->pa->time_eat_mutex);
    pthread_mutex_unlock(&ph->pa->write_mutex);
    ft_usleep(ph->pa->time_to_eat);
    pthread_mutex_unlock(ph->right_fork);
    pthread_mutex_unlock(&ph->left_fork);
    sleep_and_think(ph);
}


/*void	print_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = actual_time() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
	{
		printf(BOLD"%ld ms "CLEAR, time);
		printf("Philo %d %s", ph->id, str);
	}
}



void	sleep_and_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status(BLUE"is sleeping\n"CLEAR, ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time_to_sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status(YELLOW"is thinking\n"CLEAR, ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}



void	simulation(t_philo *ph)
{
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status(GREEN"has taken a fork\n"CLEAR, ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->right_fork)
	{
		ft_usleep(ph->pa->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status(GREEN"has taken a fork\n"CLEAR, ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status(PURPLE"is eating\n"CLEAR, ph);
	pthread_mutex_lock(&ph->pa->time_eat_mutex);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->pa->time_eat_mutex);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time_to_eat);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(&ph->left_fork);
	sleep_and_think(ph);
}*/