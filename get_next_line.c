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
	char		*new_position;
	char		*line;
	char		*buff;
	int			bytesread;
	char		*tmp;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (1)
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread <= 0)
			break;
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
	if (left_str == NULL || *left_str == '\0')
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	new_position = ft_strchr(left_str, '\n');
	if (new_position != NULL)
	{
		line_len = new_position - left_str + 1;
		line = ft_substr(left_str, 0, line_len);
		tmp = ft_strdup(new_position + 1);
		free(left_str);
		left_str = tmp;
	}
	else
	{
		line = ft_strdup(left_str);
		free(left_str);
		left_str = NULL;
		if (*line == '\0')
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
