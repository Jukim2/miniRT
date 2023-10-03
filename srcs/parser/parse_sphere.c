/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 12:54:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	parse_sphere(t_object *objects, char *line)
{
	t_sphere	*tmp;
	int			idx;

	tmp = ft_calloc(1, sizeof(t_sphere));
	if (!tmp)
		clean_program(objects, line);
	idx = parse_floats(tmp->coord, line, 2);
	check_misconfiguration(objects, line, idx);
	idx = parse_float(&tmp->diameter, line , idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_rgb(tmp->rgb, line, idx);
	check_endconfiguration(objects, line, idx);
	add_sphere(objects->sphere, tmp);
}

void	add_sphere(t_sphere *sphere, t_sphere *new)
{
	if (!sphere)
		sphere = new;
	else
	{
		while (sphere->next)
			sphere = sphere->next;
		sphere->next = new;
	}
}
