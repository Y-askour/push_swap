/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/18 19:37:51 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
 // and here
int check_max_min(char *number,char *max,char *min)
{
	printf("\n-----------\n");
	if (number[0] == '-')
	{
		if (ft_strlen(number) > 11)
			return (1);
		printf("number %s\n",number);
		printf("min    %s\n",min);
	}
	else
	{
		if (ft_strlen(number) > 10)
			return (1);
		printf("number %s\n",number);
		printf("max    %s\n",max);
	}
	return (0);
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
		// check here
		if (check_max_min(argv[i],"2147483647","-2147483648"))
			return (0);
		if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
			|| (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
			j++;
		else
		{
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]))
					return (0);
				j++;
			}
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
