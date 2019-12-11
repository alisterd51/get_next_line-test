/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:02:40 by anclarma          #+#    #+#             */
/*   Updated: 2019/11/25 14:08:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
	ret = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d: %s\n", ret, line);
		free(line);
	}
	printf("%d: %s\n", ret, line);
	free(line);
	close(fd);
	return (0);
}
