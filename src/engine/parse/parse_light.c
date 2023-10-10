/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/04 01:34:14 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->light.coord, line, 1);
	check_misconfiguration(objects, line, idx);
	idx = parse_double(&objects->light.light_ratio, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&objects->light.rgb, line, idx);
	check_endconfiguration(objects, line, idx);
}
