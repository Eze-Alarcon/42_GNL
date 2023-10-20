#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>

// BORRAR
# include <stdio.h>

char	*get_next_line(int fd);

#endif
