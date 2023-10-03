/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:44:45 by kjs               #+#    #+#             */
/*   Updated: 2023/10/03 12:55:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "libft.h" // for ft_strcmp, for gnl
#include "parse.h"
#include <fcntl.h> // for O_RDONLY
#include <stdio.h> // test

int	parse(t_object *objects, char *file_name)
{
	int		fd;
	void	(*parsers[6])(t_object *, char *);
	char	*line;

	initialize_parsers(parsers);
	fd = open(file_name, O_RDONLY);
	// check the file
	// 마지막 .의 위치를 찾아서 거기서부터 끝까지해서 '.rt'와 strcmp
	// Read the file
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		parse_line(parsers, objects, line);
	}
	return (1);
}

void	initialize_parsers(void (*parsers[])(t_object *, char *))
{
	parsers[AMBIENT_LIGHT] = parse_ambient_light;
	parsers[CAMERA] = parse_camera;
	parsers[LIGHT] = parse_light;
	parsers[SPHERE] = parse_sphere;
	parsers[PLANE] = parse_plane;
	parsers[CYLINDER] = parse_cylinder;
	parsers[ERROR] = clean_program;
}

void	parse_line(void (*parsers[])(t_object *, char *), t_object *objects, char *line)
{
	if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
	{
		printf("empty line\n");
		return ;
	}
	parsers[parse_id(objects, line)](objects, line);
}


