/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:29:18 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/17 00:20:51 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_operation(t_data *data, int check)
{
	t_list	*index0;
	t_list	*index1;

	if (data->sa_len >= 2)
	{
		index0 = data->head_l_stack_a;
		index1 = data->head_l_stack_a->next;
		data->head_l_stack_a->next = data->head_l_stack_a->next->next;
		index1->next = index0;
		data->head_l_stack_a = index1;
	}
	if (check)
		ft_putendl_fd("sa", 1);
}

void	sb_operation(t_data *data, int check)
{
	t_list	*index0;
	t_list	*index1;

	if (data->sb_len >= 2)
	{
		index0 = data->head_l_stack_b;
		index1 = data->head_l_stack_b->next;
		data->head_l_stack_b->next = data->head_l_stack_b->next->next;
		index1->next = index0;
		data->head_l_stack_b = index1;
	}
	if (check)
		ft_putendl_fd("sb", 1);
}

void	ss_operation(t_data *data)
{
	sa_operation(data, 0);
	sb_operation(data, 0);
	ft_putendl_fd("ss", 1);
}
