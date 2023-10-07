/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:27:23 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 19:13:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "raytrace.h"
#include "object.h"

/* ===============srcs/hit=============== */

double	hit_cylinder(t_ray ray, t_shape shape);
double	hit_plane(t_ray ray, t_shape *shape);
double	hit_sphere(t_ray ray, t_vec3 center, double radius);
void	set_surface_normal_vector(t_ray ray, t_shape *shape, double t);

#endif
