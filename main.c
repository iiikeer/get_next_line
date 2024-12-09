/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:17:45 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/09 11:09:37 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i = 0;
	char	*string;

	fd = 0;
	string = get_next_line(fd);
	while (i < 5)
	{
		printf("%s", string);
		free(string);
		i ++;
		string = get_next_line(fd);
	}
	printf("%s", string);
	free(string);
	close(fd);
	return (0);
}
