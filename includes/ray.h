/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:02:27 by kjs               #+#    #+#             */
/*   Updated: 2023/10/06 15:07:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vec3.h"
#include "object.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

/* ===============srcs/hit=============== */

t_vec3	get_color_vec3(t_ray ray);
double		hit_cylinder(t_ray ray, t_shape shape);
t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted);
t_shape		*find_nearest_shape(t_ray ray, t_shape *shape, double *t);
void		set_surface_normal_vector(t_ray ray, t_shape *shape, double t);
double		hit_sphere(t_ray ray, t_vec3 center, double radius);
int			convert_color_vec3(t_vec3 color_vec3);
t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j);

#endif
