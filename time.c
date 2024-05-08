#include "../include/philo.h"

void ft_usleep(long int time_in_ms)
{
    long int start_time;

    start_time = 0;
    start_time = actual_time();
    while ((actual_time() - start_time) < time_in_ms)
        usleep(time_in_ms / 10);
}

//cacl the actual time 
//need to be check one more time 
long int actual_time(void)
{
    long int time;
    struct  timeval current_time;

    time = 0;
    if(gettimeofday(&current_time, NULL) == -1)
        ft_exit("Gettimeofday returned -1\n");
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}