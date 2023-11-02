/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:44:45 by kjs               #+#    #+#             */
/*   Updated: 2023/11/02 20:32:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>

int	parse(t_objects *objs, char *filename)
{
	int		fd;
	void	(*parsers[7])(t_objects *, char *);
	char	*line;

	init_parsers(parsers);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		parse_line(parsers, objs, line);
		free(line);
	}
	close(fd);
	return (1);
}

void	init_parsers(void (*parsers[])(t_objects *, char *))
{
	parsers[PARSE_AMBIENT_LIGHT] = parse_ambient_light;
	parsers[PARSE_CAMERA] = parse_camera;
	parsers[PARSE_LIGHT] = parse_light;
	parsers[PARSE_SPHERE] = parse_sphere;
	parsers[PARSE_PLANE] = parse_plane;
	parsers[PARSE_CYLINDER] = parse_cylinder;
	parsers[PARSE_ERROR] = clean_program;
}

void	parse_line(void (*parsers[])(t_objects *, char *), \
					t_objects *objs, char *line)
{
	static int	arr[3];
	int			id;

	if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		return ;
	id = parse_id(objs, line);
	if (id < 3 && arr[id]++ != 0)
	{
		printf("miniRT: multiple symbol error\n");
		clean_program(objs, line);
	}
	parsers[id](objs, line);
}


