/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:02:27 by kjs               #+#    #+#             */
/*   Updated: 2023/10/04 17:38:45 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vector3.h"
#include "object.h"

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
}	t_ray;

/* ===============srcs/hit=============== */

t_vector3	get_color_vector3(t_ray ray);
t_vector3	get_color(t_ray ray, t_shape *shape);
t_shape	*find_nearest_shape(t_ray ray, t_shape *shape, double *t);
void		set_surface_normal_vector(t_ray ray, t_shape *shape, double t);
double		hit_sphere(t_ray ray, t_vector3 center, double radius);
int			convert_color_vector3(t_vector3 color_vec3);

#endif
