#include "header.h"

int	issorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp -> next)
	{
		if (tmp -> content > tmp -> next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

int	array_instructions(char *str, int *i)
{
	if (!ft_strncmp("sa\n", str, 3))
		return (*i);
	else if (!ft_strncmp("sb\n", str, 3))
		return (*i);
	else if (!ft_strncmp("ss\n", str, 3))
		return (*i);
	else if (!ft_strncmp("pa\n", str, 3))
		return (*i);
	else if (!ft_strncmp("pb\n", str, 3))
		return (*i);
	else if (!ft_strncmp("ra\n", str, 3))
		return (*i);
	else if (!ft_strncmp("rb\n", str, 3))
		return (*i);
	else if (!ft_strncmp("rr\n", str, 3))
		return (*i);
	else if (!ft_strncmp("rra\n", str, 4))
		return (*i);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (*i);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (*i);
	return (1);
}

static void	check_instructions(char *str, t_list **a, t_list **b)
{
	if (!ft_strncmp("sa\n", str, 3))
		swap_a(a, *a, 0);
	else if (!ft_strncmp("sb\n", str, 3))
		swap_b(b, *b, 0);
	else if (!ft_strncmp("ss\n", str, 3))
		swap_ss(a, b, 0);
	else if (!ft_strncmp("pa\n", str, 3))
		push_a(a, b, 0);
	else if (!ft_strncmp("pb\n", str, 3))
		push_b(a, b, 0);
	else if (!ft_strncmp("ra\n", str, 3))
		*a = rotate_ra(a, *a, 0);
	else if (!ft_strncmp("rb\n", str, 3))
		*b = rotate_rb(b, *b, 0);
	else if (!ft_strncmp("rr\n", str, 3))
		rotate_rr(a, b, 0);
	else if (!ft_strncmp("rra\n", str, 4))
		*a = rotate_rra(a, *a, 0);
	else if (!ft_strncmp("rrb\n", str, 4))
		*b = rotate_rrb(b, *b, 0);
	else if (!ft_strncmp("rrr\n", str, 4))
		rotate_rrr(a, b, 0);
}

void	ft_exit(int n)
{
	if (n == 0)
		write(1, "OK\n", 3);
	else if (n == -1)
		write(1, "KO\n", 3);
	exit(0);
}

void	open_prompt(t_list **a, t_list **b)
{
	char	*instructions;
	int		i;

	i = 0;
	while (1)
	{
		instructions = get_next_line(0);
		if (!instructions)
			break ;
		if (array_instructions(instructions, &i))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		check_instructions(instructions, a, b);
		free(instructions);
	}
	if (issorted(a) == 0)
		i = -1;
	ft_exit(i);
	free(a);
	free(b);
}
