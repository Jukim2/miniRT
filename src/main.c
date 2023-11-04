/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/11/05 01:06:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <fcntl.h>

static int	is_valid_argument(char *arg);
static int	is_directory(char *filename);

int	main(int argc, char **argv)
{
	t_engine	e;

	if (argc < 2)
		ft_putendl_fd("Error\nnot enough argument", 2);
	else if (argc > 2)
		ft_putendl_fd("Error\ntoo many argument", 2);
	else if (is_valid_argument(argv[1]))
	{
		if (!init_engine(&e, argv[1]))
			return (0);
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

static int	is_valid_argument(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nno such file or no permission", 2);
		return (0);
	}
	close(fd);
	if (is_directory(arg))
	{
		ft_putendl_fd("Error\nfile is a directory", 2);
		return (0);
	}
	else if (!ft_strncmp(&arg[ft_strlen(arg) - 3], ".rt", 3))
		return (1);
	else
	{
		ft_putendl_fd("Error\nfile extension is should be *.rt", 2);
		return (0);
	}
}
