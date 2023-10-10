/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:24:23 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/10 16:47:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "numft.h"
# include "object.h"
# include "engine.h"

#define SAMPLE_CNT 1

/* ===============srcs/color=============== */

void	correct_color(t_vec3 *color_vector_sum, t_shape *hitted_shape);
int		convert_color_vec3(t_vec3 color_vec3);
t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j);
int		get_color(t_engine *e, int x, int y);

#endif
