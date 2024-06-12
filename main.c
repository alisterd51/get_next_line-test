/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:02:40 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/07 19:58:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEST_ULIMIT 2000
// ulimit -Sn 2000
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/*
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
*/
int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
/*
int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		test;

	if (ac == 1)
		return (1);
	test = 3;
	while (test < TEST_ULIMIT)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		free(line);
	}
	return (0);
}
*/
