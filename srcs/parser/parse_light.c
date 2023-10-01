/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 20:00:59 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_light(t_object *objects, char *line)
{
    int idx;

    idx = parse_floats(objects->light.coord, line, 1);
    check_misconfiguration(objects, line, idx);
    idx = parse_float(&objects->light.light_ratio, line, idx);
    check_misconfiguration(objects, line, idx);
    idx = parse_rgb(objects->light.rgb, line, idx);
    check_endconfiguration(objects, line, idx);
}