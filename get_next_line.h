/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrad <conrad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:43:16 by conrad            #+#    #+#             */
/*   Updated: 2025/02/26 20:51:51 by conrad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup( const char *str1 );
size_t	ft_strlen(const char*str);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_bzero(void*str, size_t n);
#endif
