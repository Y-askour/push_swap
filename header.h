/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <yaskour@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:13:41 by yaskour           #+#    #+#             */
/*   Updated: 2022/06/19 17:15:47 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

int		ft_atoi(const char *str);
char	**split_int(char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *buffers, char *buff);
char	**ft_split(char const *s, char c);

t_list	*ft_lstadd_back(t_list **lst, t_list *tnew);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *tnew);
t_list	*ft_lstnew(int content);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		check_error(int ac, char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	open_prompt(t_list **a, t_list **b);

t_list	*swap_a(t_list **stack, t_list *list, int check);
t_list	*swap_b(t_list **stack, t_list *list, int check);
void	push_a(t_list **stack_a, t_list **stack_b, int check);
void	push_b(t_list **stack_a, t_list **stack_b, int check);
t_list	*rotate_rra(t_list **stack, t_list *list, int check);
t_list	*rotate_rrb(t_list **stack, t_list *list, int check);
t_list	*rotate_rb(t_list **stack, t_list *list, int check);
t_list	*rotate_ra(t_list **stack, t_list *list, int check);
void	rotate_rrr(t_list **stack_a, t_list **stack_b, int check);
void	rotate_rr(t_list **stack_a, t_list **stack_b, int check);
void	swap_ss(t_list **stack_a, t_list **stack_b, int check);
#endif
