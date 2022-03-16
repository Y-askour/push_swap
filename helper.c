/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:54:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/17 00:24:26 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_one_arg_helper(int *i, int *j, char **nums)
{
	while (nums[*i][*j])
	{
		if (!ft_isdigit(nums[*i][*j]))
			return (0);
		*j += 1;
	}
	return (1);
}

void	tmp_helper(t_list *ptr, int *i, int *tmp)
{
	while (ptr)
	{
		tmp[*i] = ptr->data;
		ptr = ptr->next;
		*i += 1;
	}
}

void	helper2_tmp(t_data *data, int *j, int *i, int *tmp)
{
	t_list	*ptr;

	ptr = data->head_l_stack_a;
	while (*j != data->index)
	{
		tmp[*i] = ptr->data;
		ptr = ptr->next;
		*j += 1;
		*i += 1;
	}
}

void	sort_big_helper(t_data *data, int des, int i, int number)
{
	if (des < i)
	{
		while (data->head_l_stack_a->data != number)
			rra_operation(data, 1);
	}
	else
	{
		while (data->head_l_stack_a->data != number)
			ra_operation(data, 1);
	}
}

int	number_is_between(int a, int number, int b)
{
	if (a < number && number < b)
		return (1);
	return (0);
}
