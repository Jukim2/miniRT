/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:13:05 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 14:00:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "color.h"
#include <math.h>

t_vec3	get_specular_color(t_objects *objs, t_hit_record r)
{
	t_vec3	reflected_vector;
	t_vec3	view_vector;
	t_vec3	specular_color;
	t_ray	ray;

	ray.origin = r.point;
	ray.direction = norm_vec3(sub_vec3(objs->light.coord, r.point));
	if (is_shadowed(objs->shape, ray.origin, ray.direction))
		return (vec3(0, 0, 0));
	reflected_vector = norm_vec3(add_vec3(scale_vec3(-1, ray.direction), scale_vec3(2, r.normal)));
	view_vector = norm_vec3(sub_vec3(objs->camera.coord, r.point));
	specular_color = scale_vec3(pow(dot_vec3(view_vector, reflected_vector), 15), vec3(1, 1, 1));
	return (specular_color);
}

int	get_color(t_engine *e, int x, int y)
{
	int				sampling;
	t_vec3			rgb_sum;
	t_ray			ray;
	t_vec3			offset;
	t_hit_record	r;

	sampling = 0;
	rgb_sum = vec3(0, 0, 0);
	ray.origin = e->objs.camera.coord;
	while (sampling < SAMPLE_CNT)
	{
		offset = add_vec3(scale_vec3(x + rand_double(-0.5, 0.5), e->display.px_dt[WD]), scale_vec3(y + rand_double(-0.5, 0.5), e->display.px_dt[HT]));
		ray.direction = norm_vec3(add_vec3(e->display.bot_lt_px, offset));
		rgb_sum = add_vec3(rgb_sum, raytrace(ray, &e->objs, 20));
		sampling++;
	}
	rgb_sum = scale_vec3(1. / SAMPLE_CNT, rgb_sum);
	r = get_hit_record(ray, e->objs.shape);
	if (r.is_hit)
	{
		rgb_sum = add_vec3(rgb_sum, scale_vec3(e->objs.ambient_light.ambient, r.rgb));
		correct_color(&rgb_sum, r.rgb);
		rgb_sum = add_vec3(rgb_sum, get_specular_color(&e->objs, r));
		correct_color(&rgb_sum, r.rgb);
	}
	return (convert_color_vec3(rgb_sum));
}
