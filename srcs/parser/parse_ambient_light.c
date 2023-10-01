/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 20:20:14 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>
void	parse_ambient_light(t_object *objects, char *line)
{
    int idx;

    idx = parse_float(&objects->ambient_light.light_ratio, line, 1);
    check_misconfiguration(objects, line, idx);
    idx = parse_rgb(objects->ambient_light.rgb, line, idx);
    check_endconfiguration(objects, line, idx);
}