#include "../inc/philo.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

// i represent and index for the char within each argumnet 
// j is the index of the current argument
int is_number(char **argv, int i, int j)
{
    while(argv[j])
    {
        while(argv[j][i])
        {
            if(argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
                return (0);
            i++;
        }
        i = 0;
        j++;
    }
    return (1);
}    