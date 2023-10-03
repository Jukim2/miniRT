/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 12:54:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_light(t_object *objects, char *line)
{
	int	idx;

	idx = parse_floats(objects->light.coord, line, 1);
	check_misconfiguration(objects, line, idx);
	idx = parse_float(&objects->light.light_ratio, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_rgb(objects->light.rgb, line, idx);
	check_endconfiguration(objects, line, idx);
}
