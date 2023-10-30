/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/30 16:21:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	parse_sphere(t_objects *objects, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		clean_program(objects, line);
	tmp->type = SPHERE;
	idx = parse_doubles(&tmp->coord, line, check_misconfiguration(objects, line, 2));
	idx = parse_double(&tmp->radius, line, check_misconfiguration(objects, line, idx));
	tmp->radius /= 2;
	idx = parse_doubles(&tmp->rgb, line, check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
	tmp->rgb.x /= 255.;
	tmp->rgb.y /= 255.;
	tmp->rgb.z /= 255.;
	add_shape(&objects->shape, tmp);
}

