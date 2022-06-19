#include "header.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*str)
	{
		if (*str != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (i);
}

static char	*ft_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **split, int i)
{
	while (i > 0)
	{
		free(split[i--]);
	}
	free(split);
}

static char	**ft_csplit(int index, char const *s, char c, char **split)
{
	size_t	j;
	size_t	i;

	i = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word(s, index, i);
			if (split[j - 1] == NULL)
				ft_free(split, j);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	index = -1;
	split = ft_csplit(index, s, c, split);
	return (split);
}
