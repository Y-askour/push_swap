/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:57:06 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/15 19:33:31 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate(int *a, int *b, t_data *data)
{
	if (*a < 0 && *b < 0)
	{
		if (*a < *b)
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
			return ;
		}
		else
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
			return ;
		}
	}
	else if (*a > 0 && *b > 0)
	{
		if (*a > *b)
		{
			while (*b)
			{
				rr_operation(data);
				*b -= 1;
				*a -= 1;
			}
			while (*a)
			{
				ra_operation(data, 1);
				*a -= 1;
			}
			pa_operation(data);
			return ;
		}
		else
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
			return ;
		}
	}
}

void	push(t_data *data, int index)
{
	int	a;
	int	b;	
	int	i;

	a = data->num_pos[index].a;
	b = data->num_pos[index].b;
	if ((a * b) > 0)
		smart_rotate(&a, &b, data);
	else
	{
		if (a < 0)
		{
			while (a < 0)
			{
				rra_operation(data, 1);
				a++;
			}
		}
		else
		{
			i = 0;
			while (i < a)
			{
				ra_operation(data, 1);
				i++;
			}
		}
		if (b < 0)
		{
			while (b < 0)
			{
				rrb_operation(data, 1);
				b++;
			}
			pa_operation(data);
		}
		else
		{
			i = 0;
			while (i < b)
			{
				rb_operation(data, 1);
				i++;
			}
			pa_operation(data);
		}
	}	
}

void	sort_helper(t_data *data)
{
	int	i;
	int	number;

	i = 0;
	while (data->sb_len)
	{
		stack_b_pos(data);
		number = find_best_number(data);
		push(data, number);
		free(data->num_pos);
		i++;
	}
	push_smallest_number(data, &data->head_l_stack_a);
}

void	stack_helper(t_data *data, int stack_len, char	**stack)
{
	int	i;

	i = 1;
	if (stack_len > 0)
	{
		data->sa_len = stack_len;
		data->sb_len = 0;
		data->head_l_stack_a = malloc(sizeof(t_list));
		data->head_l_stack_b = NULL;
		data->head_l_stack_a->data = ft_atoi(stack[i]);
		data->head_l_stack_a->next = NULL;
		i++;
		while (i <= stack_len)
		{
			add_at_end(data->head_l_stack_a, ft_atoi(stack[i]));
			i++;
		}
	}
}
