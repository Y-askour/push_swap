/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:13:01 by yaskour           #+#    #+#             */
/*   Updated: 2022/06/19 17:13:02 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *tnew)
{
	t_list	*p;

	if (*lst == NULL)
	{
		*lst = tnew;
		return (*lst);
	}
	else
	{
		p = NULL;
		p = *lst;
		while (p -> next)
			p = p -> next;
		p -> next = tnew;
	}
	return (*lst);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	i = 0;
	p = NULL;
	p = lst;
	while (p)
	{
		i++;
		p = p -> next;
	}
	return (i);
}

void	ft_lstadd_front(t_list **alst, t_list *tnew)
{
	tnew -> next = *alst;
	*alst = tnew;
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	ptr -> content = content;
	ptr -> next = NULL;
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;
	char	*src;

	i = 0;
	sign = 1;
	result = 0;
	src = (char *)str;
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == ' ')
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((src[i] >= '0' && src[i] <= '9') && src[i] != '\0')
	{
		result = result * 10 + src[i] - '0';
		i++;
	}
	return (result * sign);
}
