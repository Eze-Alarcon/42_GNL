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
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("\nejecucion numero %i:\n", i + 1);
    //     line = get_next_line(fd);
    //     printf("\nRespuesta en main: -->%s<--\n", line);
    //     free(line);
    //     printf("===============");
    // }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    // line = get_next_line(fd);
    // if (line != NULL)
    // {
    //     printf("\nRespuesta recibida en main:\n");
    //     printf("%s", line);
    //     free(line);
    // }
    close(fd);

    return 0;
}


