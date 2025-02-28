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
	static char	*left_str;
	int			bytesread;
	char		*new_position;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytesread = read(fd, buff, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[bytesread] = '\0';
	if (left_str == NULL)
		line = ft_strdup(buff);
	else
	{
		line = ft_strjoin(left_str, buff);
		free(left_str);
	}
	new_position = ft_strchr(line,'\n');
	if (new_position != NULL)
	{
		*new_position = '\0';
		line = ft_strdup(left_str);
		left_str = ft_strdup(new_position + 1);
	}
	else
	{
		line = ft_strdup(left_str);
		free(left_str);
		left_str = NULL;
	}
	return (line);
}
