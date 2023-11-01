/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 13:29:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->light.coord, line, check_misconfiguration(objects, line, 1));
	idx = parse_double(&objects->light.brightness, line, check_misconfiguration(objects, line, idx));
	idx = parse_doubles(&objects->light.rgb, line, check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
