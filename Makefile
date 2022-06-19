CC= gcc
NAME=push_swap
BNAME=checker
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

BONUS_SRC = checker.c\
		open_prompt.c\
		get_next_line.c\
		checker_error_help.c\
		instr.c\
		instr2.c\
		instr3.c\
		linked.c\
		check_error.c\
		ft_split.c\
		ft_strlen.c

OBJS=$(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
INCL= push_swap.h
INCLB=header.h

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

$(BNAME):$(BONUS_OBJ) 
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BNAME)

bonus : $(BNAME)

clean:
	rm -rf *.o
	rm -rf ./libft/*.o

fclean:clean
	rm -rf *.a
	rm -rf push_swap
	rm -rf checker

.PHONY: all gnl utils bonus clean fclean re

