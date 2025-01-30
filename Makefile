CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft
PRINTFDIR = ./ft_printf

SRCS = push_swap.c

BONUS = 	ft_checker.c get_next_line.c  get_next_line_utils.c ft_join_args_bns.c ft_strjoin_bonus.c \
			check_arguments.c creat_linked_list.c ft_has_duplicates_bns.c ft_strdup_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)
DELETE = rm -f
NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(NAME)


bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFTDIR)/libft.a $(PRINTFDIR)/printf.a -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(PRINTFDIR)
	$(DELETE) $(OBJS) $(BOBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	make fclean -C $(PRINTFDIR)
	$(DELETE) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
