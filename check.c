
#include "minitalk.h"

int check_pid(char *str)
{
    int i;

	i = 0;
    if (!str[0])
        return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int check_pid_max(char *str)
{
    long long nbr;
    int i;

	nbr = 0;
	i = 0;
    while (str[i])
    {
        nbr = nbr * 10 + (str[i] - '0');

        if (nbr > INT_MAX)
            return (0);
        i++;
    }
    return (1);
}
