/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 13:41:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_double(&objects->ambient_light.ambient, line, \
	check_misconfiguration(objects, line, 1));
	idx = parse_doubles(&objects->ambient_light.rgb, line, \
	check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}