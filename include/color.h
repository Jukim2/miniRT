/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:24:23 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 01:25:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "numft.h"
# include "object.h"
# include "engine.h"
# include "ray.h"

# define SAMPLE_CNT 1

/* ===============srcs/color=============== */

int		convert_color_vec3(t_vec3 color);
void	correct_color(t_vec3 *color_sum);
int		get_color(t_engine *e, int x, int y);
t_vec3	get_specular_color(t_objects *objs, t_hit_record r);
t_bool	is_valid_color_hex(t_vec3 color);

#endif
