/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/19 20:03:56 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big_numbers(t_data *data)
{
	//int small = l_by_index(data->head_l_stack_a,find_smallest_number(data,&data->head_l_stack_a));
	//int big = l_by_index(data->head_l_stack_a,find_biggest_number(data,&data->head_l_stack_a));
	if (is_sorted(data) == 1)
		return ;
	while (data->sa_len != 0)
	{
		push_smallest_number(data, &data->head_l_stack_a);
		pb_operation(data);
	}
	while (data->sb_len != 0)
		pa_operation(data);
}
