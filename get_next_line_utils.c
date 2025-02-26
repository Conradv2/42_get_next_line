/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrad <conrad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:43:04 by conrad            #+#    #+#             */
/*   Updated: 2025/02/26 20:54:23 by conrad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup( const char *str1 )
{
	char	*cpy;
	int		str1_len;

	str1_len = ft_strlen(str1);
	cpy = (char *)malloc((str1_len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (*str1 != '\0')
	{
		*cpy++ = *str1++;
	}
	*cpy = '\0';
	return (cpy - str1_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		s1_len;
	int		s2_len;
	int		tmp;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	tmp = i;
	i = 0;
	while (i < s2_len)
		s3[tmp++] = s2[i++];
	s3[tmp] = '\0';
	return (s3);
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
