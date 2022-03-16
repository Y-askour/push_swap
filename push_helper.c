/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:36:40 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/16 22:30:11 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_helper(t_data *data, int *i, int *b)
{
	if (*b < 0)
	{
		while (*b < 0)
		{
			rrb_operation(data, 1);
			*b += 1;
		}
		pa_operation(data);
	}
	else
	{
		*i = 0;
		while (*i < *b)
		{
			rb_operation(data, 1);
			*i += 1;
		}
		pa_operation(data);
	}
}

void	push_helper2(t_data *data, int *i, int *a)
{
	if (*a < 0)
	{
		while (*a < 0)
		{
			rra_operation(data, 1);
			*a += 1;
		}
	}
	else
	{
		*i = 0;
		while (*i < *a)
		{
			ra_operation(data, 1);
			*i += 1;
		}
	}
}

void	smart_rotate_helper(t_data *data, int *a, int *b)
{
	while (*b < 0)
	{
		rrr_operation(data);
		*b += 1;
		*a += 1;
	}
	while (*a < 0)
	{
		rra_operation(data, 1);
		*a += 1;
	}
	pa_operation(data);
}

void	smart_rotate_helper2(t_data *data, int *a, int *b)
{
	while (*a < 0)
	{
		rrr_operation(data);
		*b += 1;
		*a += 1;
	}
	while (*b < 0)
	{
		rrb_operation(data, 1);
		*b += 1;
	}
	pa_operation(data);
}
