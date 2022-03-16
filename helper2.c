/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:52:34 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/16 23:29:21 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_helper(int number, t_data *data, int i, t_list *ptr)
{
	if (data->big == i && number > l_by_index(data->head_l_stack_a, data->big))
		data->num_pos[data->index].a = i + 1;
	if (ptr->data < number && number < ptr->next->data)
		data->num_pos[data->index].a = i + 1;
}

void	stack_a_helper_2(int number, t_data *data, int i, t_list *ptr)
{
	if (i == data->big && number > l_by_index(data->head_l_stack_a, data->big))
		data->num_pos[data->index].a = data->j + 1;
	if (ptr->next && ptr->data < number && number < ptr->next->data)
		data->num_pos[data->index].a = data->j + 1;
}

void	find_best_number_helper(int i, int *tmp, t_data *data)
{
	if (data->num_pos[i].a < 0)
		*tmp = -data->num_pos[i].a;
	else
		*tmp = data->num_pos[i].a;
	if (data->num_pos[i].b < 0)
		*tmp += -data->num_pos[i].b;
	else
		*tmp += data->num_pos[i].b;
}

int	find_best_number(t_data	*data)
{
	t_list	*ptr;
	int		i;
	int		best_number;
	int		tmp;
	int		index;

	ptr = data->head_l_stack_b;
	i = 0;
	tmp = 0;
	index = 0;
	best_number = l_by_index(data->head_l_stack_b,
			find_biggest_number(data, &data->head_l_stack_b));
	while (ptr)
	{
		find_best_number_helper(i, &tmp, data);
		if (best_number > tmp)
		{
			best_number = tmp;
			index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (index);
}
