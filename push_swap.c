/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaskour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:58:56 by yaskour           #+#    #+#             */
/*   Updated: 2022/02/17 19:09:27 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stacks(char **stack, int stack_len, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (stack_len > 0)
	{
		data->sa_len = stack_len;
		data->sb_len = 0;
		data->head_l_stack_a = malloc(sizeof(t_list));
		data->head_l_stack_b = NULL;
		data->head_l_stack_a->data = ft_atoi(stack[i]);
		data->head_l_stack_a->next = NULL;
		i++;
		while (i <= stack_len)
		{
			add_at_end(data->head_l_stack_a, ft_atoi(stack[i]));
			i++;
		}
	}
}

void	ft_error(void)
{
	ft_putendl_fd("error", 1);
	exit(1);
}

void	print_stacks(t_data *data)
{
	int	i;

	i = 0;
	ft_putendl_fd("a  b\n", 1);
	while (i < data->sa_len || i < data->sb_len)
	{
		if (i < data->sa_len)
			ft_putnbr_fd(l_by_index(data->head_l_stack_a, i), 1);
		ft_putstr_fd(" | ", 1);
		if (i < data->sb_len)
			ft_putnbr_fd(l_by_index(data->head_l_stack_b, i), 1);
		else
			ft_putstr_fd(" ", 1);
		i++;
		ft_putstr_fd("\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!arg_is_int(argv, argc - 1) || ft_check_dup(argv, argc - 1))
		ft_error();
	stacks(argv, argc - 1, &data);
	sort_small_numbers(&data);
}
