/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/14 17:34:57 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <stdio.h>

int	push_nonlis(t_data *data, int number, int *lis)
{
	int	i;

	i = 0;
	while (i < data->lis_len)
	{
		if (number == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	stack_a_pos(t_data *data, int index, int number)
{
	t_list	*ptr;
	int		i;
	int		big;

	if (data->head_l_stack_a->data > number
		&& number > l_by_index(data->head_l_stack_a, data->sa_len - 1))
		data->num_pos[index].a = 0;
	ptr = data->head_l_stack_a;
	data->j = -data->sa_len;
	i = 0;
	big = find_biggest_number(data, &data->head_l_stack_a);
	data->index = index;
	data->big = big;
	while (ptr)
	{
		if (i < (data->sa_len - 1) / 2)
			stack_a_helper(number, data, i, ptr);
		else
			stack_a_helper_2(number, data, i, ptr);
		data->j++;
		i++;
		ptr = ptr->next;
	}
}

void	stack_b_pos(t_data *data)
{
	t_list	*ptr;
	int		i;
	int		j;
	int		des;

	data->num_pos = malloc(sizeof(t_pos) * data->sb_len);
	ptr = data->head_l_stack_b;
	j = 0;
	i = 0;
	while (ptr)
	{
		des = (data->sb_len - 1) - i;
		if (des < i)
		{
			j = i - data->sb_len;
			data->num_pos[i].b = j;
			j++;
		}
		else
			data->num_pos[i].b = i;
		stack_a_pos(data, i, ptr->data);
		ptr = ptr->next;
		i++;
	}
}

void	sort_big_numbers(t_data *data)
{
	int		*lis;
	t_list	*ptr;
	int		i;
	int		des;

	i = 0;
	lis = push_lis(data);
	ptr = data->head_l_stack_a;
	while (ptr)
	{
		if (!push_nonlis(data, ptr->data, lis))
		{
			des = (data->sa_len - 1) - i;
			sort_big_helper(data, des, i, ptr->data);
			pb_operation(data);
		}
		i++;
		ptr = ptr->next;
	}
	sort_helper(data);
	//if (data->sb_len)
	//	stack_b_pos(data);
	//find_best_number(data);
}
