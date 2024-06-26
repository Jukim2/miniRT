/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specular_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:24:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:17:12 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"
#include <math.h>

t_vec3	get_specular_color(t_objects *objs, t_hit_record r)
{
	t_ray	ray;
	t_vec3	reflected;
	t_vec3	view;
	double	dot;

	ray.origin = r.point;
	ray.direction = norm_vec3(sub_vec3(objs->light.coord, r.point));
	if (is_shadowed(objs->shape, ray.origin, ray.direction, objs->light.coord))
		return (vec3(0, 0, 0));
	reflected = norm_vec3(add_vec3(scale_vec3(-1, ray.direction), \
	scale_vec3(abs_double(dot_vec3(ray.direction, r.normal)) * 2, r.normal)));
	view = norm_vec3(sub_vec3(objs->camera.coord, r.point));
	dot = dot_vec3(view, reflected);
	if (dot > 0)
		return (scale_vec3(pow(dot, 15), objs->light.rgb));
	else
		return (vec3(0, 0, 0));
}
