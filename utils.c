/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/21 19:08:58 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_max_min(char *number, char *max, char *min)
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

int	arg_is_int_helper(char **argv, int *j, int *i)
{
	while (argv[*i][*j])
	{
		if (!ft_isdigit(argv[*i][*j]))
			return (0);
		*j += 1;
	}
	return (1);
}

int	arg_is_int(char **argv, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (len <= 0)
		return (0);
	while (i <= len)
	{
		j = 0;
		if (check_max_min(argv[i], "2147483647", "-2147483648"))
			return (0);
		if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
			|| (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
			j++;
		else
		{
			if (!arg_is_int_helper(argv, &j, &i))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dup(char **argv, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = i + 1;
		while (j <= len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_data *data)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = data->head_l_stack_a;
	while (ptr->next)
	{
		if (ptr->data > ptr->next->data)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
