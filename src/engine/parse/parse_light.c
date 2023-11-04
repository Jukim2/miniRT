/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 01:30:21 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parse.h"

void	parse_light(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_doubles(&objs->light.coord, line, \
						check_misconfig(objs, line, 1));
	idx = parse_double(&objs->light.brightness, line, \
						check_misconfig(objs, line, idx));
	if (objs->light.brightness < 0 || objs->light.brightness > 1)
		term_engine(ERR_MSG_LIGHT_BRIGHTNESS, objs, line);
	idx = parse_doubles(&objs->light.rgb, line, \
						check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(objs->light.rgb))
		term_engine(ERR_MSG_LIGHT_RGB, objs, line);
	objs->light.rgb = scale_vec3(1 / 255., objs->light.rgb);
	check_endconfig(objs, line, idx);
}
