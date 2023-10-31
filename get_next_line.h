#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif

# include <unistd.h>
# include <stdlib.h>

// BORRAR
# include <stdio.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
char    *ft_strchr(const char *str, int c);
char    *ft_strjoin(char *s1, char const *s2);

#endif
