/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/02 17:56:51 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup_one(char **argv, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_one_arg(char *arg)
{
	char	**nums;
	int		i;
	int		j;

	nums = ft_split(arg, ' ');
	i = 0;
	j = 0;
	if (!nums[0])
		return (0);
	while (nums[i])
	{
		j = 0;
		if ((nums[i][j] == '-' && ft_isdigit(nums[i][j + 1]))
			|| (nums[i][j] == '+' && ft_isdigit(nums[i][j + 1])))
			j++;
		if (!check_one_arg_helper(&i, &j, nums))
			return (0);
		i++;
	}
	if (ft_check_dup_one(nums, count_words(arg, ' ')))
		return (0);
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
