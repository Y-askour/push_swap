/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:19 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/17 19:14:48 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_operation(t_data *data, int check)
{
	if (data->sa_len > 1)
		r_rotate_core(&data->head_l_stack_a, data->sa_len);
	if (check)
		ft_putendl_fd("rra", 1);
}

void	rrb_operation(t_data *data, int check)
{
	if (data->sb_len > 1)
		r_rotate_core(&data->head_l_stack_b, data->sa_len);
	if (check)
		ft_putendl_fd("rrb", 1);
}

void	rrr_operation(t_data *data)
{
	rrb_operation(data, 0);
	rra_operation(data, 0);
	ft_putendl_fd("rrr", 1);
}
