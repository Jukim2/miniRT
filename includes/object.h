/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:45:23 by kjs               #+#    #+#             */
/*   Updated: 2023/10/03 21:35:08 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "vector3.h"

typedef struct s_ambient_light
{
	double		light_ratio;
	t_vector3	rgb;
} t_ambient_light;

typedef struct s_camera
{
	t_vector3	coord;
	t_vector3	forward_vector;
	double		fov;
	// Not sure fov is double or int
} t_camera;

typedef struct s_light
{
	double		light_ratio;
	t_vector3	coord;
	t_vector3	rgb;
} t_light;

typedef struct s_shape
{
	struct s_shape	*next;
	int				type;
	double			diameter;
	double			height;
	t_vector3		coord;
	t_vector3		normal_vector;
	t_vector3		rgb;
}	t_shape;

typedef struct s_objects
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_shape			*shape;
} t_objects;

#endif