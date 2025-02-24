/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkruszyn <kkruszyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:43:04 by conrad            #+#    #+#             */
/*   Updated: 2025/02/23 14:32:33 by kkruszyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void*str, size_t n)
{
	char	*ptr;
	char	c;

	ptr = (char *)str;
	c = 0;
	while (n != 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	if (nitems > 0 && size > ((size_t) - 1) / nitems)
		return (NULL);
	str = malloc(nitems * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nitems * size);
	return ((void *)str);
}

size_t	ft_strlen(const char*str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
