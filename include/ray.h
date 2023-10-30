/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:22:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/30 14:49:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "numft.h"
#include "object.h"
#include "engine.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_hit_record
{
	t_bool	is_hit;
	double	t;
	t_vec3	point;
	t_vec3	normal;

	t_bool	is_front;
	t_vec3	rgb;
	int		mat;
}	t_hit_record;

/* ===============srcs/raytrace=============== */

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth);
t_hit_record	get_hit_record(t_ray ray, t_shape *shape);
void	init_hit_record(t_hit_record *record);
t_vec3	get_reflected_direction(t_ray ray, t_hit_record record);
int		is_shadowed(t_shape *shape, t_ray reflected_ray, t_vec3 light);
t_hit_record	hit_circle(t_ray ray, t_shape *shape);
t_hit_record	hit_cylinder(t_ray ray, t_shape *shape);
t_hit_record	hit_plane(t_ray ray, t_shape *shape);
t_hit_record	hit_sphere(t_ray ray, t_shape *shape);

#endif
