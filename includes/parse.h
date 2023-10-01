/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:27 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 19:48:24 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

enum e_object
{
    AMBIENT_LIGHT = 0,
    CAMERA = 1,
    LIGHT = 2,
    SPHERE = 3,
    PLANE = 4,
    CYLINDER = 5,
    ERROR = 6
};

/* ===============srcs/parser=============== */

int		parse(t_object *objects, char *file_name);
void	initialize_parsers(void (*parsers[])(t_object *, char *));
void	parse_line(void (*parsers[])(t_object *, char *), t_object *objects, char *line);
void	parse_ambient_light(t_object *objects, char *line);
void	parse_camera(t_object *objects, char *line);
void	parse_cylinder(t_object *objects, char *line);
void	add_cylinder(t_cylinder *cylinder, t_cylinder *new);
void	parse_light(t_object *objects, char *line);
int		parse_id(t_object *objects, char *line);
int		parse_rgb(int rgb[3], char *line, int idx);
int		parse_int(int *n, char *line, int idx);
int		parse_float(float *f, char *str, int i);
int		parse_floats(float floats[3], char *line, int idx);
void	parse_plane(t_object *objects, char *line);
void	add_plane(t_plane *plane, t_plane *new);
void	parse_sphere(t_object *objects, char *line);
void	add_sphere(t_sphere *sphere, t_sphere *new);
void	clean_program(t_object *objects, char *line);
void	check_misconfiguration(t_object *objects, char *line, int idx);
void	check_endconfiguration(t_object *objects, char *line, int idx);

#endif
