#include "header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while ((st1[i] != '\0' || st2[i] != '\0') && (i < n))
	{
		if ((st1[i] < st2[i]) || (st1[i] > st2[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_max_min(int c, char *p)
{
	char	*str;
	char	*str1;
	int		i;

	str = "-2147483648";
	str1 = "2147483647";
	i = 0;
	if (c == -2147483648)
	{
		while (str[i])
			*p++ = str[i++];
		*p = '\0';
		return (1);
	}
	i = 0;
	if (c == 2147483647)
	{
		while (str1[i])
			*p++ = str1[i++];
		*p = '\0';
		return (1);
	}
	return (0);
}


static int	get_len(int num)
{
	int	l;

	l = 0;
	if (num <= 0)
		l = 1;
	while (num)
	{
		num /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		i;
	int		x;
	char	*p;

	x = get_len(n) + 1;
	p = malloc(x * sizeof(char));
	if (!p)
		return (NULL);
	if (ft_max_min(n, p))
		return (p);
	if (n < 0)
	{
		n = -n;
		p[0] = '-';
	}
	p[x - 1] = '\0';
	i = x - 2;
	while ((i >= 0 && n > 0) || (n == 0 && x-- == 2))
	{
		p[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (p);
}
