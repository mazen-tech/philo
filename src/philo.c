#include "../inc/philo.h"

int main(int ac, char **av)
{
    t_p p;

    if(!(args(ac, av, &p)))
        return (ft_exit("Invalid Arguments"));
    p.ph = malloc(sizeof(t_philo) * p.a.philos);
    if (!p.ph)
        return (ft_exit("Malloc returned NULL \n"));
    if(!initialize(&p) || !threading(&p))
    {
        free(p.ph);
        return (0);
    }
    stop (&p);
    return (0);
} 