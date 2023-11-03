/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/03 17:36:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "object.h"
#include "parse.h"
#include "libft.h"
#include <stdio.h>

void	parse_sphere(t_objects *objs, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		clean_program(objs, line);
	tmp->type = SPHERE;
	idx = parse_doubles(&tmp->coord, line, check_misconfig(objs, line, 2));
	idx = parse_double(&tmp->radius, line, check_misconfig(objs, line, idx));
	tmp->radius /= 2;
	if (doublecmp(tmp->radius, 0) <= 0)
	{
		printf("Error\nSphere Radius should be bigger than zero\n");
		clean_program(objs, line);
	}
	idx = parse_doubles(&tmp->rgb, line, check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(tmp->rgb))
	{
		printf("Error\nSphere RGB should be between [0-255]\n");
		clean_program(objs, line);
	}
	check_endconfig(objs, line, idx);
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	add_shape(&objs->shape, tmp);
}

