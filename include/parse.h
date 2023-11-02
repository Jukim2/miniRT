/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:27 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/02 15:50:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "object.h"

enum e_parse
{
    PARSE_AMBIENT_LIGHT = 0,
    PARSE_CAMERA = 1,
    PARSE_LIGHT = 2,
    PARSE_SPHERE = 3,
    PARSE_PLANE = 4,
    PARSE_CYLINDER = 5,
    PARSE_ERROR = 6
};

/* ===============srcs/parser=============== */

void	parse_camera(t_objects *objects, char *line);
void	parse_sphere(t_objects *objects, char *line);
void	clean_program(t_objects *objects, char *line);
int		check_misconfig(t_objects *objects, char *line, int idx);
void	check_endconfiguration(t_objects *objects, char *line, int idx);
void	add_shape(t_shape **shape, t_shape *new);
int		parse_id(t_objects *objects, char *line);
int		parse_double(double *f, char *str, int i);
int		parse_doubles(t_vec3 *vec, char *line, int idx);
void	parse_ambient_light(t_objects *objects, char *line);
void	parse_light(t_objects *objects, char *line);
int		parse(t_objects *objects, char *file_name);
void	initialize_parsers(void (*parsers[])(t_objects *, char *));
void	parse_line(void (*parsers[])(t_objects *, char *), t_objects *objects, char *line);
void	parse_cylinder(t_objects *objects, char *line);
void	parse_plane(t_objects *objects, char *line);

#endif
