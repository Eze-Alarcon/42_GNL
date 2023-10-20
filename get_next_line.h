#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif

# include <unistd.h>
# include <stdlib.h>

// BORRAR
# include <stdio.h>

char	*get_next_line(int fd);

#endif
