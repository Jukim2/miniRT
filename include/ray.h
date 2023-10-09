/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:22:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/09 19:28:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vec3.h"
#include "object.h"
#include "engine.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_hit
{
	double	t;
	t_vec3	p;
	t_vec3	n;
}	t_hit;

/* ===============srcs/raytrace=============== */

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted);
t_shape	*get_hit_shape(t_ray ray, t_shape *shape, double *t);
t_vec3	random_on_hemisphere(const t_shape *shape);
t_vec3	get_reflected_direction(t_ray ray, t_shape *hitted_shape);
int		is_shadowed(t_shape *shape, t_ray reflected_ray, t_vec3 light);
double	hit_circle(t_ray ray, t_shape *shape);
double	hit_cylinder(t_ray ray, t_shape *shape);
double	hit_plane(t_ray ray, t_shape *shape);
double	hit_sphere(t_ray ray, t_vec3 center, double radius);
void	set_surface_normal_vector(t_ray ray, t_shape *shape, double t);

#endif
