/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:27 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 10:38:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "object.h"

# define ERR_MSG_WRONG_SYMBOL "Wrong Symbol Detected"
# define ERR_MSG_AMBIENT_RATIO "Ambient Light should be between [0,0,1.0]"
# define ERR_MSG_AMBIENT_RGB "Ambient Light RGB be betwwen [0-255]"
# define ERR_MSG_CAM "Camera Orientation Vector must have values in [-1,1]"
# define ERR_MSG_CAM_ORIENT_LEN "Camera Orientation Vector should have length"
# define ERR_MSG_CAM_FOV "Camera filed of view should be in [0,180]"
# define ERR_MSG_LIGHT_BRIGHTNESS "Light brightness should be in [0.0,1.0]"
# define ERR_MSG_LIGHT_RGB "Light RGB should be between [0-255]"
# define ERR_MSG_CY "Cylinder Orient Vector must have values in [-1,1]"
# define ERR_MSG_CY_ORIENT_LEN "Cylinder Orientation Vector should have length"
# define ERR_MSG_CY_RGB "Cylinder RGB should be betwwen [0-255]"
# define ERR_MSG_PL "Plane Orientation Vector must have values in [-1,1]"
# define ERR_MSG_PL_ORIENT_LEN "Plane Orientation Vector should have length"
# define ERR_MSG_PL_RGB "Plane RGB should be between [0-255]"
# define ERR_MSG_SPHERE_RADIUS "Sphere Radius should be bigger than zero"
# define ERR_MSG_SHPERE_RGB "Sphere RGB should be between [0-255]"
# define ERR_MSG_SHAPE_NOT_ALLOC "Shape does not allocated"

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

void	parse_camera(t_objects *objs, char *line);
void	parse_sphere(t_objects *objs, char *line);
void	parse_failed(t_objects *objs, char *line);
int		check_misconfig(t_objects *objs, char *line, int idx);
void	check_endconfig(t_objects *objs, char *line, int idx);
void	add_shape(t_shape **shape, t_shape *new);
t_bool	is_valid_norm_vector(t_vec3	n);
int		parse_id(char *line);
int		parse_double(double *f, char *str, int i);
int		parse_doubles(t_vec3 *vec, char *line, int idx);
void	parse_ambient_light(t_objects *objs, char *line);
void	parse_light(t_objects *objs, char *line);
int		parse(t_objects *objs, char *filename);
void	init_parsers(void (*parsers[])(t_objects *, char *));
void	parse_line(void (*parsers[])(t_objects *, char *), \
					t_objects *objs, char *line);
void	parse_cylinder(t_objects *objs, char *line);
void	parse_plane(t_objects *objs, char *line);

#endif
