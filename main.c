#include "get_next_line.h"

// fileno(FILE) obtiene el fd de un puntero FILE
int main() {
	FILE *file = fopen("text.txt", "r");
	int fd = fileno(file);

	if (fd != -1)
	{
		get_next_line(fd);
	}
	else
	{
		printf("Error al obtener el descriptor de archivo");
		return (1);
	}
	fclose(file);
	return 0;
}

