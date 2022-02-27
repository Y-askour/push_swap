/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:10:01 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/27 17:25:54 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct linkedlist
{
	int					data;
	struct linkedlist	*next;
}	t_list;

typedef struct num_pos
{
	int a;
	int b;
}	t_pos;

typedef struct data
{
	int		sa_len;
	int		sb_len;
	int		push_value;
	t_list	*head_l_stack_a;
	t_list	*head_l_stack_b;
	int	lis_len;
	t_pos *num_pos;

}	t_data;

int find_mid(t_data	*data);
// main functions

void	stacks(char **stack, int stack_len, t_data *data);
int		ft_check_dup(char **argv, int len);
int		arg_is_int(char **argv, int len);

// operation core

void	push_b(t_data *data);
void	push_a(t_data *data);
void	rotate_core(t_list	**head, int len);
void	r_rotate_core(t_list **head, int len);

// swap operation

void	sa_operation(t_data *data, int check);
void	sb_operation(t_data *data, int check);
void	ss_operation(t_data *data);

// push operation

void	pb_operation(t_data *data);
void	pa_operation(t_data *data);

// rotate operation

void	ra_operation(t_data *data, int check);
void	rb_operation(t_data *data, int check);
void	rr_operation(t_data *data);

// reverse rotate operation
void	rra_operation(t_data *data, int check);
void	rrb_operation(t_data *data, int check);
void	rrr_operation(t_data *data);

// sort_small_numbers

void	random_3(t_data *data, t_list **head);
void	random_4(t_data *data, t_list **head);
void	random_5(t_data *data, t_list **head);
void	sort_small_numbers(t_data *data);

// sort utils
int		find_smallest_number(t_data *data, t_list	**head);
int		find_biggest_number(t_data *data, t_list	**head);
void	push_smallest_number(t_data *data, t_list	**head);
int		is_sorted(t_data *data);
int check_one_arg(char *arg);
size_t	count_words(char const *str, char c);
int	ft_check_dup_one(char **argv, int len);

// sort_big_numbers

void	sort_big_numbers(t_data *data);

// print stacks
void	print_stacks(t_data *data);

//linkedlist functions

void	add_at_end(t_list *head, int number);
int		l_by_index(t_list *head, int index);
void	add_at_top(t_list	**head, t_list	*node);
t_list	*copy_node(t_list	*node);
void	deletenode(t_list	**head);
void lis(int *arr,int *arr1,int len);
int *tmp(t_data *data);
int *push_lis(t_data *data);
#endif
