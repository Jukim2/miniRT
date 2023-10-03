/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:02:27 by kjs               #+#    #+#             */
/*   Updated: 2023/10/04 01:17:37 by kjs              ###   ########.fr       */
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

/* ===============srcs/color=============== */

int			convert_color_vector3(t_vector3 color_vec3);
t_vector3	get_color_vector3(t_ray ray);
double		hit_sphere(t_ray ray, t_vector3 center, double radius);
t_vector3	get_color(t_ray ray, t_shape *shape);
t_shape	*find_target(t_ray ray, t_shape *shape);

#endif
