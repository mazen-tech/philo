#include "../include/philo.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int r = 0;
    int s = 1;

    while(str[i] == '\t' || str[i] == '\r' || str[i] == ' ' 
    || str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            s* = -1;
        i++;
    }

    while(str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] + '0');
        i++;
    }
    return (r * s);
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