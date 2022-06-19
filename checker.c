#include "header.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buffers, char *buff)
{
	int		i;
	int		j;
	char	*new;

	if (!buffers)
	{
		buffers = (char *)malloc(sizeof(char));
		buffers[0] = '\0';
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(buffers)
				+ ft_strlen(buff) + 2));
	if (new == 0)
		return (0);
	i = -1;
	j = 0;
	while (buffers[++i])
		new[i] = buffers[i];
	while (buff[j])
		new[i++] = buff[j++];
	new[ft_strlen(buffers) + ft_strlen(buff)] = '\0';
	free (buffers);
	return (new);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	len;
	char	*dp;
	int		i;

	ss = (char *)s;
	len = ft_strlen(ss);
	i = 0;
	dp = (char *)malloc((len + 1) * sizeof(char));
	if (dp == NULL)
		return (NULL);
	while (ss[i] != '\0')
	{
		dp[i] = ss[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}

char	**split_int(char **av)
{
	char	*str;
	char	**split;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (av[i])
	{
		str = ft_strjoin(ft_strjoin(str, av[i]), " ");
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

t_list	**fill_stack_bonus(t_list **stack_a, char **split)
{
	int	i;

	*stack_a = NULL;
	i = 0;
	while (split[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	char	**split;
	t_list	**a;
	t_list	**b;

	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	*b = NULL;
	*a = NULL;
	if (ac == 1)
		return (0);
	split = split_int(av);
	if (!check_error(ac, split))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	a = fill_stack_bonus(a, split);
	open_prompt(a, b);
	return (0);
}

