#include "get_next_line.h"

char    *ft_read(int fd, char *read_str)
{
    char    *tmp_str;
    int     readed_chars;

    tmp_str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!tmp_str)
        return (NULL);
    readed_chars = 1;
    while (!ft_strchr(read_str, '\n') && readed_chars != 0)
    {
        readed_chars = read(fd, tmp_str, BUFFER_SIZE);
        if (readed_chars == -1)
        {
            free(tmp_str);
            return (NULL);
        }
        tmp_str[readed_chars] = '\0';
        read_str = ft_strjoin(read_str, tmp_str);
    }
    free(tmp_str);
    return (read_str);
}

char	*ft_getline(char *read_str)
{
	int		len;
	char	*line;

	len = 0;
	if (!read_str)
		return (NULL);
	while (read_str[len] && read_str[len] != '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = (char * )malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, read_str, len + 2);
	return (line);
}

char	*ft_leftovers(char *read_str)
{
	int		len;
	char	size;
	char	*leftovers;

	len = 0;
	while (read_str[len] && read_str[len] != '\n')
		len++;
	if (!read_str[len])
	{
		free(read_str);
		return (NULL);
	}
	size = ft_strlen(read_str) - len;
	if (size == 0)
		return (NULL);
	leftovers = (char *)malloc(size + 1 * sizeof(char));
	if (!leftovers)
		return (NULL);
	ft_strlcpy(leftovers, read_str + len + 1, BUFFER_SIZE);
	return (leftovers);
}

char	*get_next_line(int fd)
{
    static char	*read_str;
    char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_str = ft_read(fd, read_str);
	if (!read_str)
		return (NULL);
	line = ft_getline(read_str);
	read_str = ft_leftovers(read_str);
	if (!read_str)
		return (NULL);
	return (line);
}
