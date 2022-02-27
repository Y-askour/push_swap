/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/27 15:39:36 by yaskour          ###   ########.fr       */
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
	//int i = 0;
	//while(i < data->lis_len)
	//{
	//	printf("%d\n",lis[i]);
	//	i++;
	//}
	t_list *ptr;
	int i = 0;
	ptr =data->head_l_stack_a;
	int des;
	while(ptr)
	{
		if (!push_nonlis(data,ptr->data,lis))
		{
			des = (data->sa_len - 1) - i;
			if (des < i)
			{
				while(data->head_l_stack_a->data != ptr->data)
					rra_operation(data,1);
				pb_operation(data);
			}
			else
			{
				while(data->head_l_stack_a->data != ptr->data)
					ra_operation(data,1);
				pb_operation(data);
			}
		}
		i++;
		ptr = ptr->next;
	}
	//print_stacks(data);
}
