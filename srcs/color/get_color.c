/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:13:05 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/28 01:25:29 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "engine.h"
#include "object.h"
#include "raytrace.h"
#include "color.h"
#include "utils.h"
#include <math.h>

t_vec3	get_color(t_engine *e, t_vec3 px_center)
{
	int		sampling;
	t_ray	ray;
	t_vec3	sample_pixel;
	t_vec3	color_vector_sum;
	t_shape	*hitted_shape;

	sampling = 0;
	hitted_shape = 0;
	color_vector_sum = vec3(0, 0, 0);
	// ray.origin = e->objs.camera.coord;
	ray.origin = vec3(0, 0, 0);

	/* start rotation quaternion */
	t_vec3 c = cross_vec3(vec3(0, 0, -1), e->objs.camera.forward_vector);
	c = norm_vec3(c);

	double cosine = dot_vec3(vec3(0, 0, -1), e->objs.camera.forward_vector);
	double s_half = sqrt((1.0 - cosine) / 2.0);
	double c_half = sqrt((1.0 + cosine) / 2.0);
	
	// q = cos(θ/2) + (x * sin(θ/2), y * sin(θ/2), z * sin(θ/2))
	t_quat q = quat(c_half, c.x * s_half, c.y * s_half, c.z * s_half);
	q = norm_quat(q);

	/* end rotation quaternion */

	while (sampling < SAMPLE_CNT)
	{
		sample_pixel = add_vec3(px_center, vec3((-0.5 + random_double_zerone()) * e->display.px_dt[WD], (-0.5 + random_double_zerone()) * e->display.px_dt[HT], 0));
		ray.direction = norm_vec3(sub_vec3(px_center, ray.origin));


		t_quat a = quat(0, ray.direction.x, ray.direction.y, ray.direction.z);
		// t_quat rotated = q * a * q-1;
		t_quat temp = mult_quat(q, a);
		t_quat conjugate = get_conj_quat(q);
		t_quat rotated = mult_quat(temp, conjugate);
		// ray.direction = norm_vec3(vec3(rotated.v.x, rotated.v.y, rotated.v.z));



		color_vector_sum = add_vec3(color_vector_sum, raytrace(ray, e->objs.shape, 50, &hitted_shape));
		sampling++;
	}
	color_vector_sum = scale_vec3(1. / SAMPLE_CNT, color_vector_sum);
	if (hitted_shape)
	{
		color_vector_sum = add_vec3(color_vector_sum, scale_vec3(0.2, hitted_shape->rgb));
		correct_color(&color_vector_sum, hitted_shape); // 이게 맞나
	}
	return (color_vector_sum);
}
