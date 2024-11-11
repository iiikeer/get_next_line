/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:17:45 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/10 12:33:55 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*string;

	fd = open ("test1.txt", O_RDONLY);
	string = get_next_line(fd);
	while (string != NULL)
	{
		printf("%s", string);
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	return (0);
}
