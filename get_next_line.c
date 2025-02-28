/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrad <conrad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:48:19 by conrad            #+#    #+#             */
/*   Updated: 2025/02/26 20:55:40 by conrad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	char		*tmp;
	static char	*left_str;
	int			bytesread;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while((bytesread = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytesread] = '\0';
		if (left_str == NULL)
			left_str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(left_str, buff);
			free(left_str);
			left_str = tmp;
		}
		if (ft_strchr(buff, '\n') != NULL )
			break;
	}
	return (line);
}
