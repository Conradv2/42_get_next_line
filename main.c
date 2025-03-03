#include "get_next_line.h"
#include "stdio.h"

int main(void)
{
	int     fd;
	char    *line;
	int	i;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file"); // Print error if file can't be opened
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line) // Check for NULL before printing
			break;
		printf("line[%02d] : %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
