/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:59:25 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/09 09:36:31 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_next_line(int fd, char *next_line);
char	*get_line(char *next_line, char *buffer);
void	clean_line(char *next_line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_strcpy(char *dst, char *src, size_t dstsize);

#endif