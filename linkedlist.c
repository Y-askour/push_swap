/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:49 by yaskour           #+#    #+#             */
/*   Updated: 2022/03/02 17:18:13 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	deletenode(t_list	**head)
{
	t_list	*temp;

	if (!*head)
		return ;
	temp = *head;
	*head = temp->next;
	free(temp);
}

t_list	*copy_node(t_list	*node)
{
	t_list	*c_node;

	if (!node)
		return (NULL);
	c_node = malloc(sizeof(t_list));
	c_node->data = node->data;
	c_node->next = 0;
	return (c_node);
}

void	add_at_top(t_list	**head, t_list	*node)
{
	if (!*head)
		*head = node;
	else
	{
		node->next = *head;
		*head = node;
	}
}

void	add_at_end(t_list *head, int number)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = head;
	temp = malloc(sizeof(t_list));
	temp->data = number;
	temp->next = NULL;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
}

int	l_by_index(t_list *head, int index)
{
	t_list	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (ptr)
	{
		if (i == index)
			return (ptr->data);
		ptr = ptr->next;
		i++;
	}
	return (0);
}
