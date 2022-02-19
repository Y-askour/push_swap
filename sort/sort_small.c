/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:42:46 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/18 13:06:22 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	random_3(t_data *data, t_list **head)
{
	if ((l_by_index(*head, 0) > l_by_index(*head, 1))
		&& (l_by_index(*head, 1) < l_by_index(*head, 2))
		&& (l_by_index(*head, 0) < l_by_index(*head, 2)))
		sa_operation(data, 1);
	if ((l_by_index(*head, 0) > l_by_index(*head, 1))
		&& (l_by_index(*head, 1) > l_by_index(*head, 2)))
	{
		sa_operation(data, 1);
		rra_operation(data, 1);
	}
	if ((l_by_index(*head, 0) > l_by_index(*head, 1))
		&& (l_by_index(*head, 1) < l_by_index(*head, 2)))
		ra_operation(data, 1);
	if ((l_by_index(*head, 0) < l_by_index(*head, 1))
		&& (l_by_index(*head, 1) > l_by_index(*head, 2))
		&& (l_by_index(*head, 0) < l_by_index(*head, 2)))
	{
		sa_operation(data, 1);
		ra_operation(data, 1);
	}
	if ((l_by_index(*head, 0) < l_by_index(*head, 1))
		&& (l_by_index(*head, 1) > l_by_index(*head, 2)))
		rra_operation(data, 1);
}

void	random_4(t_data *data, t_list **head)
{
	int	i;

	i = 0;
	if (is_sorted(data))
		return ;
	push_smallest_number(data, head);
	pb_operation(data);
	random_3(data, head);
	pa_operation(data);
}

void	random_5(t_data *data, t_list **head)
{
	if (is_sorted(data))
		return ;
	push_smallest_number(data, head);
	pb_operation(data);
	random_4(data, head);
	pa_operation(data);
}

void	sort_small_numbers(t_data *data)
{
	if (data->sa_len == 2)
	{
		if (data->head_l_stack_a->data > data->head_l_stack_a->next->data)
			sa_operation(data, 1);
	}
	if (data->sa_len == 3)
		random_3(data, &data->head_l_stack_a);
	if (data->sa_len == 4)
		random_4(data, &data->head_l_stack_a);
	if (data->sa_len == 5)
		random_5(data, &data->head_l_stack_a);
}
