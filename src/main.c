/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/11/02 16:22:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>

static int	check_argument(char *arg);
static int	is_directory(char *filename);

int	main(int argc, char **argv)
{
	t_engine	e;

	if (argc < 2)
		printf("miniRT: not enough argument\n");
	else if (argc > 2)
		printf("miniRT: too many argument\n");
	else if (check_argument(argv[1]))
	{
		init_engine(&e, argv[1]);
		execute_engine(&e);
	}
	return (0);
}

static int	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	else
		return (0);
}

static int	check_argument(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		printf("miniRT: no such file or directory\n");
		return (0);
	}
	close(fd);
	if (is_directory(arg))
	{
		printf("miniRT: file shouldn't be a directory\n");
		return (0);
	}
	else if (!ft_strncmp(&arg[ft_strlen(arg) - 3], ".rt", 3))
		return (1);
	else
	{
		printf("miniRT: file extension is should be *.rt\n");
		return (0);
	}
}
