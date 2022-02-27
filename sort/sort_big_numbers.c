/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/27 18:54:18 by yaskour          ###   ########.fr       */
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

void	stack_a_pos(t_data *data)
{
	// i need to loop for each number in b to find its place in a
	// had code ghalt tayloopi 3la a
	t_list	*ptr;
	t_list	*ptr2;
	ptr = data->head_l_stack_b;
	
	while(ptr)
	{
		printf("stack b %d\n---------------\n",ptr->data);
		ptr2 = data->head_l_stack_a;
		while(ptr2)
		{
			printf("stack a %d\n",ptr2->data);
			ptr2 = ptr2->next;
		}
		printf("-----------------\n");
		ptr = ptr->next;
	}
}

void	stack_b_pos(t_data *data)
{
	t_list	*ptr;
	int	i;
	data->num_pos = malloc(sizeof(t_pos) * data->sb_len);
	ptr = data->head_l_stack_b;
	i = 0;
	int j = 0;
	int des;
	while(ptr)
	{
		des = (data->sb_len - 1) - i;
		if (des < i)
		{
			j = i - data->sb_len;
			data->num_pos[i].b = j;
			j++;
		}
		else
			data->num_pos[i].b = i;
		ptr = ptr->next;
		i++;
	}
	stack_a_pos(data);
}

void	sort_big_numbers(t_data *data)
{
	int *lis = push_lis(data);
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
					rra_operation(data,0);
				pb_operation(data);
			}
			else
			{
				while(data->head_l_stack_a->data != ptr->data)
					ra_operation(data,0);
				pb_operation(data);
			}
		}
		i++;
		ptr = ptr->next;
	}
	if (data->sb_len)
		stack_b_pos(data);
	print_stacks(data);
}
