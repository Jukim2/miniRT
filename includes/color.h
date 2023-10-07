/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:24:23 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 16:37:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "vec3.h"
#include "object.h"
#include "engine.h"

/* ===============srcs/color=============== */

void	correct_color(t_vec3 *color_vector_sum, t_shape *hitted_shape);
int		convert_color_vec3(t_vec3 color_vec3);
t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j);
t_vec3	get_color(t_engine *e, t_vec3 px_center);

#endif
