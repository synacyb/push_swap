CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_creat_node.c ft_lstadd_back.c ft_print_list.c ft_swap.c\
		ft_push_b.c ft_push_a.c ft_rotate.c ft_free_stack.c \
		ft_valide_argument.c ft_split.c ft_strdup.c ft_strlen.c ft_strchr.c ft_strcmp.c \
		ft_substr.c ft_strjoin.c ft_memcpy.c ft_reverse_rotate.c ft_lstlast.c ft_lstadd_front.c ft_min_value.c \
		ft_join_args.c ft_find_position.c ft_sort_list.c ft_lstsize.c ft_find_min_push_b.c ft_2rndom_nbr.c ft_full_sort.c \
		ft_insertion_sort.c ft_sort_stack.c ft_last_sort.c free_args.c is_sorted.c 


OBJS = $(SRCS:.c=.o)
DELETE = rm -f
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
