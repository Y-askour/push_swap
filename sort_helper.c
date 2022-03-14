/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:57:06 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/14 17:45:02 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void push(t_data *data,int index)
{
	int a;
	int b;	
	int i;

	a = data->num_pos[index].a;
	b = data->num_pos[index].b;
	//printf("a = %d b = %d\n",a,b);
	if (a < 0)
	{
		while(a < 0)
		{
			rra_operation(data,1);
			a++;
		}
	}
	else
	{
		i = 0;
		while(i < a)
		{
			ra_operation(data,1);
			i++;
		}
	}
	if (b < 0)
	{
		while(b < 0)
		{
			rrb_operation(data,1);
			b++;
		}
		pa_operation(data);
	}
	else
	{
		i = 0;
		while(i < b)
		{
			rb_operation(data,1);
			i++;
		}
		pa_operation(data);
	}
	// add a 
}
void sort_helper(t_data *data)
{
	int i = 0;
	//int j;
	//t_list	*ptr;
	while(data->sb_len)
	{
		//printf("-------------------- pos number -----------------\n");
		stack_b_pos(data);
		//ptr = data->head_l_stack_b;
		//j = 0;
		//while(ptr)
		//{
		//	printf("a = %d   b = %d\n",data->num_pos[j].a,data->num_pos[j].b);
		//	j++;
		//	ptr = ptr->next;
		//}
		//printf("----------------------------------------------------\n");
		int number = find_best_number(data);
		//printf("best number is %d\n",number);
		push(data,number);
		//printf("----------------------------------------------------\n");
		free(data->num_pos);
		i++;
		//print_stacks(data);
	}
}
