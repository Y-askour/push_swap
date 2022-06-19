#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# define BUFFER_SIZE 2

size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);

#endif
