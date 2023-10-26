/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:44:45 by kjs               #+#    #+#             */
/*   Updated: 2023/10/26 16:43:16 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "libft.h" // for ft_strcmp, for gnl
#include "parse.h"
#include <fcntl.h> // for O_RDONLY
#include <stdio.h> // for print err

int	parse(t_objects *objects, char *file_name)
{
	int		fd;
	void	(*parsers[7])(t_objects *, char *);
	char	*line;

	initialize_parsers(parsers);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nWrong file name\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		parse_line(parsers, objects, line);
		free(line);
	}
	close(fd);
	return (1);
}

void	initialize_parsers(void (*parsers[])(t_objects *, char *))
{
	parsers[PARSE_AMBIENT_LIGHT] = parse_ambient_light;
	parsers[PARSE_CAMERA] = parse_camera;
	parsers[PARSE_LIGHT] = parse_light;
	parsers[PARSE_SPHERE] = parse_sphere;
	parsers[PARSE_PLANE] = parse_plane;
	parsers[PARSE_CYLINDER] = parse_cylinder;
	parsers[PARSE_ERROR] = clean_program;
}

void	parse_line(void (*parsers[])(t_objects *, char *), t_objects *objects, char *line)
{
	static int	arr[3];
	int			id;
	
	if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		return ;
	id = parse_id(objects, line);
	if (id < 3 && arr[id]++ != 0)
	{
		printf("Error\nMultiple symbol\n");
		free(line);
		exit(1);
	}
	parsers[parse_id(objects, line)](objects, line);
}


