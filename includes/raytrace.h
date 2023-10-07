/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:22:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 12:01:46 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

#include "vec3.h"
#include "object.h"
#include "engine.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

/* ===============srcs/raytrace=============== */

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted);
t_shape	*find_hitted_shape(t_ray ray, t_shape *shape, double *t);
t_vec3	random_on_hemisphere(const t_shape *shape);
t_vec3	get_reflected_direction(t_ray ray, t_shape *hitted_shape);

#endif
