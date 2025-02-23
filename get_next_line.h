/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkruszyn <kkruszyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:43:16 by conrad            #+#    #+#             */
/*   Updated: 2025/02/23 14:12:39 by kkruszyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd);
size_t  ft_strlen(const char*str);
void    ft_putstr_fd(char *s, int fd);
#endif
