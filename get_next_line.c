#include "get_next_line.h"

int	has_line_break(char *buffer, int size)
{
	int	i;

	i = 0;
	while (buffer[i] && i <= size)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char	*buffer;
	size_t	chars;

	printf("buffer = %i\n", BUFFER_SIZE);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	chars = read(fd, buffer, BUFFER_SIZE);
	if (chars == 0)
		return (NULL);
	*(buffer + chars + 1) = '\0';
	if (chars != 0)
		printf("has line break: %i\n", has_line_break(buffer, BUFFER_SIZE));
	printf("buffer: %s\n chars = %lu", buffer, chars);
	free(buffer);
	return (buffer);
}
