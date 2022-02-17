/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:43:21 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/17 19:12:06 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_core(t_list	**head, int len)
{
	t_list	*ptr;

	if (!*head)
		return ;
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *head;
	*head = (*head)->next;
	ptr->next->next = 0;
}

void	r_rotate_core(t_list **head, int len)
{
	t_list	*ptr;

	if (!*head)
		return ;
	ptr = *head;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = *head;
	*head = ptr->next;
	ptr->next = 0;
}
