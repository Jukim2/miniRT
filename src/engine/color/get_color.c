/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:13:05 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 01:27:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include "numft.h"
#include "ray.h"

int	get_color(t_engine *e, int x, int y)
{
	int				sampling;
	t_vec3			rgb_sum;
	t_ray			ray;
	t_hit_record	r;

	sampling = 0;
	rgb_sum = vec3(0, 0, 0);
	ray.origin = e->objs.camera.coord;
	while (sampling < SAMPLE_CNT)
	{
		ray.direction = norm_vec3(add_vec3(e->display.bot_lt_px, \
		add_vec3(scale_vec3(x + rand_double(-0.5, 0.5), e->display.px_dt[WD]), \
		scale_vec3(y + rand_double(-0.5, 0.5), e->display.px_dt[HT]))));
		rgb_sum = add_vec3(rgb_sum, raytrace(ray, &e->objs, 20));
		sampling++;
	}
	rgb_sum = scale_vec3(1. / SAMPLE_CNT, rgb_sum);
	r = get_hit_record(ray, e->objs.shape);
	if (r.is_hit)
	{
		rgb_sum = add_vec3(rgb_sum, multi_vec3(e->objs.ambient.rgb, r.rgb));
		rgb_sum = add_vec3(rgb_sum, get_specular_color(&e->objs, r));
		correct_color(&rgb_sum);
	}
	return (convert_color_vec3(rgb_sum));
}
