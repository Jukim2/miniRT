/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 20:00:52 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_camera(t_object *objects, char *line)
{
    int idx;

    idx = parse_floats(objects->camera.coord, line, 1);
    check_misconfiguration(objects, line, idx);
    idx = parse_floats(objects->camera.forward_vector, line, idx);
    check_misconfiguration(objects, line, idx);
    idx = parse_float(&objects->camera.fov, line, idx);
    check_endconfiguration(objects, line, idx);
    // printf("%f,%f,%f  %f,%f,%f %f\n", objects->camera.coord[0], objects->camera.coord[1], objects->camera.coord[2]
    // ,objects->camera.forward_vector[0], objects->camera.forward_vector[1],objects->camera.forward_vector[2]
    // , objects->camera.fov );

}