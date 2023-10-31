#include "get_next_line.h"

char    *ft_read(int fd, char *read_str)
{
    int     readed_chars;
    char    *tmp_str;

    readed_chars = -1;
    tmp_str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!tmp_str)
        return (NULL);
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
	char	*line;
	int		len;

	len = 0;
	while (read_str[len])
	{
		if (read_str[len] == '\n' || read_str[len] == '\0')
			break ;
		len++;
	}
	line = (char * )malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, read_str, len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
    static char	*read_str;
    char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    read_str = ft_read(fd, read_str);
    if (!read_str)
		return (NULL);
	line = ft_getline(read_str);
	
	printf("\nline --> %s\n", line);
	printf("\nstr --> %s\n", read_str);
    return (read_str);
}
