/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:58:39 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/17 13:30:54 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_line(char *next_line)
{
	int		indx;
	int		refc;
	char	*line;

	indx = 0;
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
		indx ++;
	if (!next_line[indx])
	{
		free(next_line);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(next_line) - indx + 1));
	if (!line)
		return (NULL);
	refc = 0;
	indx ++;
	while (next_line[indx] != '\0')
		line[refc++] = next_line[indx++];
	line[refc] = '\0';
	free(next_line);
	return (line);
}

char	*ft_get_line(const char *next_line)
{
	int		indx;
	char	*line;

	indx = 0;
	if (!next_line[indx])
		return (NULL);
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
		indx ++;
	line = malloc(sizeof(char) * (indx + 2));
	if (!line)
		return (NULL);
	indx = 0;
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
	{
		line[indx] = next_line[indx];
		indx ++;
	}
	if (next_line[indx] == '\n')
		line[indx++] = '\n';
	line[indx] = '\0';
	return (line);
}

char	*ft_read_next_line(int fd, char *next_line)
{
	int		read_buffer;
	char	*buffer;

	read_buffer = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_buffer != 0 && !ft_strchr(next_line, '\n'))
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_buffer] = '\0';
		next_line = ft_strjoin(next_line, buffer);
	}
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = ft_read_next_line(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_get_line(next_line);
	next_line = ft_clean_line(next_line);
	return (line);
}
