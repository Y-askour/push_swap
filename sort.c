/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:42:33 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/17 00:21:53 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_smallest_number(t_list	**head)
{
	int		i;
	int		small;
	int		index;
	t_list	*ptr;

	i = 0;
	ptr = *head;
	while (ptr)
	{
		if (i == 0 || small > ptr->data)
		{
			small = ptr->data;
			index = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (index);
}

int	find_biggest_number(t_list	**head)
{
	int		i;
	int		big;
	int		index;
	t_list	*ptr;

	i = 0;
	ptr = *head;
	while (ptr)
	{
		if (i == 0 || big < ptr->data)
		{
			big = ptr->data;
			index = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (index);
}

void	push_smallest_number(t_data *data, t_list	**head)
{
	int	index;
	int	small;
	int	des;

	index = find_smallest_number(head);
	small = l_by_index(*head, index);
	des = (data->sa_len - 1) - index;
	if (des < index)
	{
		while ((*head)->data != small)
			rra_operation(data, 1);
	}
	else
	{
		while ((*head)->data != small)
			ra_operation(data, 1);
	}
}
