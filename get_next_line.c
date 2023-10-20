#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	size_t	chars;

	printf("buffer = %i\n", BUFFER_SIZE);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	chars = read(fd, buffer, BUFFER_SIZE);
	*(buffer + chars + 1) = '\0';
	printf("buffer: %s\n chars = %lu", buffer, chars);
	free(buffer);
	return (buffer);
}
