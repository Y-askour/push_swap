/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/26 19:19:56 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	push_nonlis(t_data *data,int number,int *lis)
{
	int i = 0;
	while(i < data->lis_len)
	{
		if (number == lis[i])
			return 1;
		i++;
	}
	return (0);
}

void	sort_big_numbers(t_data *data)
{
	int *lis = push_lis(data);
//	int i = 0;
//	while(i < data->lis_len)
//	{
//		printf("%d\n",lis[i]);
//		i++;
//	}
	t_list *ptr;
	ptr =data->head_l_stack_a;
	while(ptr)
	{
		if (push_nonlis(data,ptr->data,lis))
		{
			printf("%d\t",ptr->data);
		}
		ptr = ptr->next;
	}
	//while (data->sa_len != 0)
	//{
	//	push_smallest_number(data, &data->head_l_stack_a);
	//	pb_operation(data);
	//}
	//while (data->sb_len != 0)
	//	pa_operation(data);
}
