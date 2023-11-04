/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:44:45 by kjs               #+#    #+#             */
/*   Updated: 2023/11/05 01:22:15 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>

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
	parsers[PARSE_ERROR] = parse_failed;
}

void	parse_line(void (*parsers[])(t_objects *, char *), \
					t_objects *objs, char *line)
{
	static int	arr[3];
	int			id;

	if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		return ;
	id = parse_id(line);
	if (id < 3 && arr[id]++ != 0)
		term_engine("miniRT: multiple symbol in configuration", objs, line);
	parsers[id](objs, line);
}
