CC = cc
#CFLAGS = -g -Wall -Wextra -Werror
SRCS = ./libft/ft_atoi.c ./libft/ft_creat_node.c ./libft/ft_lstadd_back.c ./libft/ft_print_list.c libft/ft_swap.c\
			ft_printf/ft_putnbr_fd.c ft_printf/ft_putstr_fd.c ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c \
			ft_printf/ft_puthxs_l.c ft_printf/ft_unsignedint.c ft_printf/ft_puthxs_u.c ft_printf/ft_putadress.c \
			libft/ft_push_b.c libft/ft_push_a.c libft/ft_rotate.c libft/ft_free_stack.c \
			libft/ft_valide_argument.c libft/ft_split.c libft/ft_strdup.c libft/ft_strlen.c \
			libft/ft_substr.c libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_reverse_rotate.c libft/ft_lstlast.c libft/ft_lstadd_front.c libft/ft_min_value.c \
			libft/ft_join_args.c libft/ft_find_position.c libft/ft_sort_list.c libft/ft_lstsize.c libft/ft_find_min_push_b.c libft/ft_2rndom_nbr.c libft/ft_full_sort.c \
			libft/ft_insertion_sort.c libft/ft_sort_stack.c libft/ft_last_sort.c libft/free_args.c push_swap.c \
# BONUS =
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)
DELETE = rm -f
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY: clean
