CC= gcc
NAME=push_swap
FLAGS= -Wall -Wextra -Werror
SRCS=helper.c\
	 helper2.c\
	 linkedlist.c\
	 lis.c\
	 push_helper.c\
	 push_swap.c\
	 smart_rotate_helper.c\
	 sort_helper.c\
	 utils.c\
	 core_operations.c\
	 push.c\
	 reverse_rotate.c\
	 rotate.c\
	 swap.c\
	 sort.c\
	 sort_big_numbers.c\
	 sort_small.c

OBJS=$(SRCS:.c=.o)
INCL= push_swap.h

GREY=$'\x1b[30m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

all:$(NAME)
%.o: %.c $(INCL)
	$(CC) $(FLAGS) $< $(INCL) -c

$(NAME):$(OBJS)
	make -C ./libft
	mv ./libft/libft.a .
	$(CC) $(FLAGS) $(OBJS) libft.a -o $(NAME)

clean:
	rm -rf *.o
	rm -rf ./libft/*.o

fclean:clean
	rm -rf *.a
	rm -rf push_swap

.PHONY: all gnl utils bonus clean fclean re

