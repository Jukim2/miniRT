/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/26 14:35:42 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->light.coord, line, check_misconfiguration(objects, line, 1));
	idx = parse_double(&objects->light.light_ratio, line, check_misconfiguration(objects, line, idx));
	idx = parse_doubles(&objects->light.rgb, line, check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
