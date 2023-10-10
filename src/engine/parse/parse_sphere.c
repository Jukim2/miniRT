/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/05 23:28:44 by kjs              ###   ########.fr       */
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
	idx = parse_doubles(&tmp->coord, line, 2);
	check_misconfiguration(objects, line, idx);
	idx = parse_double(&tmp->diameter, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&tmp->rgb, line, idx);
	check_endconfiguration(objects, line, idx);
	tmp->rgb.x /= 255.;
	tmp->rgb.y /= 255.;
	tmp->rgb.z /= 255.;
	add_shape(&objects->shape, tmp);
}

