/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:36:39 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/16 22:47:33 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate_helper4(t_data *data, int *a, int *b)
{
	while (*a)
	{
		rr_operation(data);
		*b -= 1;
		*a -= 1;
	}
	while (*b)
	{
		rb_operation(data, 1);
		*b -= 1;
	}
	pa_operation(data);
}
