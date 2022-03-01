/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:37:43 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/01 19:59:36 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:20:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/01 15:37:24 by yaskour          ###   ########.fr       */
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

void	stack_a_pos(t_data *data,int index,int number)
{
	int index_a[data->sa_len];
	int i = 0;
	int j;
	int des;
	while(i < data->sa_len)
	{
		des = (data->sa_len - 1) - i;
		if (des < i)
		{
			j = i - data->sa_len;
			index_a[i] = j;
		}
		else
			index_a[i] = i;
		i++;
	}
	//printf("%d\n",index_a[4]);
	i = 0;
	t_list *ptr;
	ptr = data->head_l_stack_a;
	int big  = find_biggest_number(data,&data->head_l_stack_a);
	if (data->head_l_stack_a->data > number && number > l_by_index(data->head_l_stack_a,data->sa_len - 1))
		data->num_pos[index].a = 0;
	while(ptr)
	{
		if (big < number && big == i)
		{
			data->num_pos[index].a = index_a[i];
			return ;
		}
		if (index_a[i] < 0)
		{
			if ( ptr->next != 0 && ptr->data < number && number  < ptr->next->data)
			{
				data->num_pos[index].a = index_a[i];
				return ;
			}
		}
		else
		{
			if (ptr->data < number && number < ptr->next->data)
			{
				data->num_pos[index].a = index_a[i];
				return ;
			}
		}
		i++;
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
			stack_a_pos(data,i,ptr->data);
			j++;
		}
		else
		{
			data->num_pos[i].b = i;
			stack_a_pos(data,i,ptr->data);
		}
		ptr = ptr->next;
		i++;
	}
	ptr = data->head_l_stack_b;
	i = 0;
	while(ptr)
	{
		printf("a = %d  b = %d\n",data->num_pos[i].a,data->num_pos[i].b);
		i++;
		ptr = ptr->next;
	}
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
