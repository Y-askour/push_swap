#include "header.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(char *number, char *max, char *min)
{
	char	*num;

	if (ft_strlen(number) >= 10)
	{
		if (number[0] == '-' && ft_strlen(number) >= 11)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, number, ft_strlen(min)))
				return (1);
		}
		if (number[0] == '+' && ft_strlen(number) >= 11)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, &number[1], 11))
				return (1);
		}
		else if (ft_strlen(number) >= 10)
		{
			num = ft_itoa(ft_atoi(number));
			if (ft_strncmp(num, number, ft_strlen(max)))
				return (1);
		}
		free(num);
	}
	return (0);
}

int	ft_isnbr(char *av)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (av[i] == '-' || av[i] == '+')
	{
		i = 1;
		if (len == 1)
			return (0);
	}
	while (i < len)
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		if (!ft_isnbr(av[i]) || ft_isint(av[i], "2147483647", "-2147483648"))
			return (0);
		i++;
	}
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(int ac, char **av)
{
	int	i;
	int	j;

	(void)ac;
	i = 0;
	j = 0;
	if (!duplicate(av))
		return (0);
	return (1);
}

