#include "client.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	long	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			signe = signe * -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > 2147483647)
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
	return (nb * signe);
}
