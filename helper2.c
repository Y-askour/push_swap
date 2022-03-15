/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:52:34 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/15 19:15:08 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	max_int(char *num, char *compare)
{
	int	i;

	i = 0;
	if (ft_strlen(num) == ft_strlen(compare))
	{
		while (i < ft_strlen(compare) - 1)
		{
			if (num[i] == compare[i])
				i++;
		}
		if (num[i] != compare[i])
			return (1);
	}
	if (ft_strlen(compare) < ft_strlen(num))
		return (1);
	return (0);
}
