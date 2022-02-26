/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:45:22 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/26 18:53:04 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int *tmp(t_data *data)
{
	int index;
	int i;
	t_list	*ptr;
	int	*tmp;
	int j;

	tmp = malloc(sizeof(int) * data->sa_len);

	index = find_smallest_number(data,&data->head_l_stack_a);
	i = 0;
	ptr = data->head_l_stack_a;
	while(i != index)
	{
		ptr = ptr->next;
		i++;
	}
	i = 0;
	while(ptr)
	{
		tmp[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}
	j = 0;
	ptr = data->head_l_stack_a;
	while(j != index)
	{
		tmp[i] = ptr->data;
		ptr = ptr->next;
		i++;
		j++;
	}
	return (tmp);
}

void lis(int *arr,int *arr1,int len)
{
    int i;
    int big;
    int n;

    i = 0;
    while(i < len)
        arr1[i++] = 1;
    big = 0;
    n = len -1;
    while(n>=0)
    {
      if (n == len -1)
        arr1[n] = 1;
      else
      {
        i = n;
        big = 0;
        while(i < len)
        {
          if (arr[n] < arr[i] && arr1[i] > big)
          {
            big = arr1[i];
          }
          i++;
        }
        arr1[n] += big;
      }
      n--;
    }
}

int *push_lis(t_data *data)
{
	int *arr = tmp(data);
	int *arr1 = malloc(sizeof(int) * data->sa_len);
	
	int i = 0;
	lis(arr,arr1,data->sa_len);
	i = 0;
	int big = arr1[0];
	int *lis = malloc(sizeof(int) * big);
	data->lis_len = big;
	while(i < data->sa_len)
	{
		if (arr1[i] == big)
		{
			lis[big -1] = arr[i];
			big--;
		}
		i++;
	}
    return (lis);
}
