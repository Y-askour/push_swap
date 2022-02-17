/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:31:31 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/17 17:23:49 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_operation(t_data *data, int check)
{
	if (data->sa_len > 1)
		rotate_core(&data->head_l_stack_a, data->sa_len);
	if (check)
		ft_putendl_fd("ra", 1);
}

void	rb_operation(t_data *data, int check)
{
	if (data->sb_len > 1)
		rotate_core(&data->head_l_stack_b, data->sb_len);
	if (check)
		ft_putendl_fd("rb", 1);
}

void	rr_operation(t_data *data)
{
	rb_operation(data, 0);
	ra_operation(data, 0);
	ft_putendl_fd("rr", 1);
}
