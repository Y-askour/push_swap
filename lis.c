/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:45:22 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/17 00:14:05 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*tmp(t_data *data)
{
	int		i;
	t_list	*ptr;
	int		*tmp;
	int		j;

	tmp = malloc(sizeof(int) * data->sa_len);
	data->index = find_smallest_number(&data->head_l_stack_a);
	i = 0;
	ptr = data->head_l_stack_a;
	while (i != data->index)
	{
		ptr = ptr->next;
		i++;
	}
	i = 0;
	tmp_helper(ptr, &i, tmp);
	j = 0;
	helper2_tmp(data, &j, &i, tmp);
	return (tmp);
}

void	lis_f(int *arr, int *arr1, int len)
{	
	int	i;
	int	big;
	int	n;

	i = 0;
	while (i < len)
		arr1[i++] = 1;
	n = len -1;
	while (n >= 0)
	{
		if (n != len -1)
		{
			i = n;
			big = 0;
			while (i < len)
			{
				if (arr[n] < arr[i] && arr1[i] > big)
					big = arr1[i];
				i++;
			}
			arr1[n] += big;
		}
		n--;
	}
}

int	*push_lis(t_data *data)
{
	int	*arr;
	int	*arr1;
	int	i;
	int	big;
	int	*lis;

	arr = tmp(data);
	arr1 = malloc(sizeof(int) * data->sa_len);
	lis_f(arr, arr1, data->sa_len);
	i = 0;
	big = arr1[0];
	lis = malloc(sizeof(int) * big);
	data->lis_len = big;
	while (i < data->sa_len)
	{
		if (arr1[i] == big)
		{
			lis[big -1] = arr[i];
			big--;
		}
		i++;
	}
	free(arr);
	free(arr1);
	return (lis);
}
