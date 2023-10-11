/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:13:05 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/11 20:49:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "color.h"
#include <math.h>

int	get_color(t_engine *e, int x, int y)
{
	t_ray	ray;
	int		sampling;
	t_vec3	color_vector_sum;

	sampling = 0;
	color_vector_sum = vec3(0, 0, 0);
	ray.origin = e->objs.camera.coord;
	while (sampling < SAMPLE_CNT)
	{
		t_vec3 offset = add_vec3(scale_vec3(x + rand_double(-0.5, 0.5), e->display.px_dt[WD]), \
								scale_vec3(y + rand_double(-0.5, 0.5), e->display.px_dt[HT]));
		ray.direction = norm_vec3(add_vec3(e->display.bot_lt_px, offset));
		color_vector_sum = add_vec3(color_vector_sum, raytrace(ray, e->objs.shape, 20));
		sampling++;
	}
	color_vector_sum = scale_vec3(1. / SAMPLE_CNT, color_vector_sum);
	t_hit_record r = get_hit_record(ray, e->objs.shape);
	if (r.is_hit)
	{
		color_vector_sum = add_vec3(color_vector_sum, scale_vec3(0.2, r.hit_shape->rgb));
		correct_color(&color_vector_sum, r.hit_shape); // 이게 맞나
	}
	return (convert_color_vec3(color_vector_sum));
}
