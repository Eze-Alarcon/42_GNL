#include "get_next_line.h"

#include <fcntl.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo");
        return 1;
    }

    char *line;
    /* while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    } */
    line = get_next_line(fd);
    if (line != NULL)
    {
        printf("\nRespuesta recibida en main:\n");
        printf("%s", line);
        free(line);
    }
    close(fd);

    return 0;
}


