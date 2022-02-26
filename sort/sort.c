/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:42:33 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/20 15:36:16 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <stdio.h>

int find_mid(t_data	*data)
{
	int	*arr;
	t_list	*ptr;
	int i;
	int j;

	arr = malloc(sizeof(int) * data->sa_len);
	ptr = data->head_l_stack_a;
	i =0;
	while(ptr)
	{
		arr[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	while(i < data->sa_len -1)
	{
		j = i + 1;
		while(j < data->sa_len)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
			j++;
		}
		i++;
	}
	int mid = (data->sa_len -1)/2;
	return (arr[mid]);
}
int	find_smallest_number(t_data *data, t_list	**head)
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


int	find_biggest_number(t_data *data, t_list	**head)
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

	index = find_smallest_number(data, head);
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
