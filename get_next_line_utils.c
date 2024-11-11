/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:59:01 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/10 17:33:57 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		indx;
	int		refc;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (!new_string)
		return (NULL);
	indx = 0;
	while (s1 && s1[indx] != '\0')
	{
		new_string[indx] = s1[indx];
		indx++;
	}
	refc = 0;
	while (s2 && s2[refc] != '\0')
		new_string[indx++] = s2[refc++];
	new_string[indx] = '\0';
	if (s1)
		free(s1);
	return (new_string);
}
