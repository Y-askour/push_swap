/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:30:36 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/17 00:20:10 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_operation(t_data *data)
{
	t_list	*node;

	if (data->sa_len > 0)
	{
		node = copy_node(data->head_l_stack_a);
		add_at_top(&data->head_l_stack_b, node);
		deletenode(&data->head_l_stack_a);
		data->sa_len--;
		data->sb_len++;
	}
	ft_putendl_fd("pb", 1);
}

void	pa_operation(t_data *data)
{
	t_list	*node;

	if (data->sb_len > 0)
	{
		node = copy_node(data->head_l_stack_b);
		add_at_top(&data->head_l_stack_a, node);
		deletenode(&data->head_l_stack_b);
		data->sb_len--;
		data->sa_len++;
	}
	ft_putendl_fd("pa", 1);
}
