#include "get_next_line.h"
#include "stdio.h"

int main(void)
{
	int     fd;
	char    *line;
	int	i;

	i = 1;
	fd = open("robus.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line) // Check for NULL before printing
			break;
		//printf("line[%02d] : %s", i, line);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
