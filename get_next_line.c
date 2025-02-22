/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrad <conrad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:40:37 by conrad            #+#    #+#             */
/*   Updated: 2025/02/22 23:58:18 by conrad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t  ft_strlen(const char*str)
{
        size_t  counter;

        counter = 0;
        while (*str != '\0')
        {
                counter++;
                str++;
        }
        return (counter);
}

void    ft_putstr_fd(char *s, int fd)
{
        int     len;
        int     i;

        i = 0;
        len = ft_strlen(s);
        while (i < len)
        {
                write(fd, &s[i], 1);
                i++;
        }
}


char	*get_next_line(int fd)
{
	char	*buff;
	ssize_t	bytesRead;
	// int		i;
	// static size_t index;

	// i = 0;
	// index = 0;
	if (fd < 0 )
	{
		perror("Error while opening a file");
		return (NULL);
	}
	buff = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	// while(buff[i] != '\n')
	// 	index += buff[i + 1];
	bytesRead = read(fd, buff, BUFFER_SIZE);
	if (bytesRead < 0)
		perror("Error while reading a file");
	buff[bytesRead] = '\0';
	return (buff);
}

int main()
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		// printf("%s", line);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}


// int main()
// {	
// 	int		fd;
// 	ssize_t bytesRead;
// 	char	*buff;
// 	size_t	line_len;
// 	int i;

// 	i = 0;
// 	buff = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buff)
// 		return (1);
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("error opening a file");
// 		free(buff);
// 		return (1);
// 	}
// 	bytesRead = read(fd, buff, BUFFER_SIZE);
// 	if (bytesRead < 0)
// 	{
// 		perror("Error reading a file");
// 		free(buff);
// 		close(fd);
// 		return (1);
// 	}
// 	buff[bytesRead] = '\0';
// 	line_len = ft_strlen(buff);
// 	// ft_putstr_fd(buff, 1);
// 	printf("buff len = %ld\n", line_len);
// 	// fflush(stdout);
// 	while(buff[i] != '\n')
// 	{
// 		write(1, &buff[i], 1);
// 		i++;
// 	}
// 	i++;
// 	while(buff[i] != '\n')
// 	{
// 		write(1, &buff[i], 1);
// 		i++;
// 	}
// 	i++;
// 	while(buff[i] != '\n')
// 	{
// 		write(1, &buff[i], 1);
// 		i++;
// 	}
// 	free(buff);
// 	close(fd);
// 	return (0);
// }


// int main()
// {
// 	int		fd;
// 	ssize_t bytesRead;
// 	ssize_t bytesRead2;
// 	char	*buff;
// 	char	*buff2;
	
// 	buff = (char *)calloc(BUFFER_SIZE, sizeof(char));
// 	fd = open("text.txt", O_RDONLY);
// 	bytesRead = read(fd, buff, BUFFER_SIZE);
// 	buff[bytesRead] = '\0';
// 	ft_putstr_fd(buff, 1);
// 	write(1,"\n", 2);
// 	buff2 = (char *)calloc(BUFFER_SIZE, sizeof(char));
// 	bytesRead2 = read(0, buff2, BUFFER_SIZE);
// 	buff2[bytesRead2] = '\0';
// 	ft_putstr_fd(buff2, 1);
// 	close(fd);
// 	return (0);
// }
