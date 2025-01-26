#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

#include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//all prototype bunos !!
char	*find_line(int fd, char *str, char *buffer);
char	*ft_strjoin3(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strdup_bns(const char *str);
char	*ft_strjoin_bns(char const *s1, char const *s2);
char	*ft_join_args_bns(char **argv);
#endif