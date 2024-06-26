/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:45:23 by kjs               #+#    #+#             */
/*   Updated: 2023/11/01 15:24:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "numft.h"

enum e_object
{
	ERROR = 0x00,
	AMBIENT_LIGHT = 0x01,
	CAMERA = 0x02,
	LIGHT = 0x03,
	SPHERE = 0x11,
	PLANE = 0x12,
	CYLINDER = 0x13,
	CONE = 0x14,
	HYPERBOLOID = 0x15,
	PARABOLOID = 0x16,
	CIRCLE = 0x21,
};

enum e_face
{
	UNKNOWN = 0,
	FRONT = 1,
	BACK = 2
};

enum e_material
{
	SCATTER = 0,
	MIRROR = 1
};

typedef struct s_ambient_light
{
	double	ambient;
	t_vec3	rgb;
}	t_ambient_light;

// Not sure fov is double or int
typedef struct s_camera
{
	t_vec3	coord;
	t_vec3	forward;
	double	fov;
}	t_camera;

typedef struct s_light
{
	double	brightness;
	t_vec3	coord;
	t_vec3	rgb;
}	t_light;

typedef struct s_shape
{
	struct s_shape	*next;
	int				type;
	int				face;
	int				mat;
	double			radius;
	double			height;
	t_vec3			coord;
	t_vec3			orient;
	t_vec3			rgb;
}	t_shape;

typedef struct s_objects
{
	t_ambient_light	ambient;
	t_camera		camera;
	t_light			light;
	t_shape			*shape;
}	t_objects;

#endif