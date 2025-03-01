/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrad <conrad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:48:47 by conrad            #+#    #+#             */
/*   Updated: 2025/03/01 18:48:49 by conrad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	char		*buff;
	int		bytesread;
	char		*tmp;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[bytesread] = '\0';
		if (left_str == NULL)
			left_str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(left_str, buff);
			free(left_str);
			left_str = tmp;
		}
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	free(buff);
	line = ft_strdup(left_str);
	free(left_str);
	left_str = NULL;
	return (line);
}

