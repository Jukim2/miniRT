/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:27 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/04 01:36:50 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "object.h"

enum e_object
{
    SPHERE = 0,
    PLANE = 1,
    CYLINDER = 2,
    AMBIENT_LIGHT = 3,
    CAMERA = 4,
    LIGHT = 5,
    ERROR = 6
};

/* ===============srcs/parser=============== */

void	parse_camera(t_objects *objects, char *line);
void	parse_sphere(t_objects *objects, char *line);
void	clean_program(t_objects *objects, char *line);
void	check_misconfiguration(t_objects *objects, char *line, int idx);
void	check_endconfiguration(t_objects *objects, char *line, int idx);
void	add_shape(t_shape **shape, t_shape *new);
int		parse_id(t_objects *objects, char *line);
int		parse_double(double *f, char *str, int i);
int		parse_doubles(t_vector3 *vec, char *line, int idx);
void	parse_ambient_light(t_objects *objects, char *line);
void	parse_light(t_objects *objects, char *line);
int		parse(t_objects *objects, char *file_name);
void	initialize_parsers(void (*parsers[])(t_objects *, char *));
void	parse_line(void (*parsers[])(t_objects *, char *), t_objects *objects, char *line);
void	parse_cylinder(t_objects *objects, char *line);
void	parse_plane(t_objects *objects, char *line);

#endif
