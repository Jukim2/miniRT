/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/02 20:17:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

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
	idx = parse_doubles(&tmp->rgb, line, check_misconfig(objs, line, idx));
	check_endconfiguration(objs, line, idx);
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	add_shape(&objs->shape, tmp);
}

