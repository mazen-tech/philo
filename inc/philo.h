#ifndef PHILO_H
# define PHILO_H

// libraries
# include <unistd.h>	// write
# include <string.h>	// memset
# include <stdio.h>		// printf 
# include <stdlib.h>	// malloc, free
# include <sys/time.h>	// gettimeofday 
# include <sys/types.h>	// usleep
# include <pthread.h>	// pthread

// colors
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CLEAR "\033[0m"
# define BOLD "\033[1m"

// structures
typedef struct s_stats
{
	int						philos;//integetr number of philos
	int						time_to_die;//time takes for philo to die
	int						time_to_eat;//time takes for philo to eat
	int						time_to_sleep;//time takes for philo to sleep
	int						meals;//number of meals each philo must eat 
	int						number_philos_ate;//number of meals eaten by philos
	int						stop_t;//stop simulation
	long int				start_t;//starting time of simulation
	pthread_mutex_t			write_mutex;//mutex used to control access output
	pthread_mutex_t			dead_mutex;//mutex used to cntrol the philo's death condition
	pthread_mutex_t			time_eat_mutex;
	pthread_mutex_t			finish_mutex;//access to some data related to finishing the semulation
}							t_stats;

typedef struct s_philo
{
	int						id;
	int						finish;
	long int				ms_eat;
	unsigned int			nb_philo_ate;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_stats					*pa;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_stats					a;
}							t_p;

// args.c
int		args(int argc, char **argv, t_p *p);

// check.c
void	stop(t_p *p);
int		check_death(t_philo *ph, int i);
int		ft_exit(char *str);

// init.c
void	init_mutex(t_p *p);
int     initialize(t_p *p);

// simulation.c
void	print_status(char *str, t_philo *ph);
void	sleep_and_think(t_philo *ph);
void	simulation(t_philo *ph);

// threads.c
void	*is_dead(void	*data);
void	*thread(void *data);
int		threading(t_p *p);

// time.c
void	ft_usleep(long int time_in_ms);
long	int	actual_time(void);

// utilities.c
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		is_number(char **argv, int i, int j);

#endif