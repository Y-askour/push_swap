/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:54:55 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/18 16:41:28 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tmp_helper(t_list *ptr, int *i, int *tmp)
{
	while (ptr)
	{
		tmp[*i] = ptr->data;
		ptr = ptr->next;
		*i += 1;
	}
}

void	helper2_tmp(t_data *data, int *j, int *i, int *tmp)
{
	t_list	*ptr;

	ptr = data->head_l_stack_a;
	while (*j != data->index)
	{
		tmp[*i] = ptr->data;
		ptr = ptr->next;
		*j += 1;
		*i += 1;
	}
}
