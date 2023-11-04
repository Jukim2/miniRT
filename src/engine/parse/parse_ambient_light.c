/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/04 17:05:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_double(&objs->ambient.ambient, line, \
	check_misconfig(objs, line, 1));
	if (objs->ambient.ambient < 0 || objs->ambient.ambient > 1)
		term_engine(ERR_MSG_AMBIENT_RATIO, objs, line);
	idx = parse_doubles(&objs->ambient.rgb, line, \
	check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(objs->ambient.rgb))
		term_engine(ERR_MSG_AMBIENT_RGB, objs, line);
	objs->ambient.rgb = scale_vec3(1 / 255., objs->ambient.rgb);
	objs->ambient.rgb = scale_vec3(objs->ambient.ambient, objs->ambient.rgb);
	check_endconfig(objs, line, idx);
}
