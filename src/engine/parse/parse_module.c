/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:21:53 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/02 20:24:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include "numft.h"
#include <stdio.h> // test

int	parse_id(t_objects *objects, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (ft_strncmp(line, "A", i) == 0)
		return (PARSE_AMBIENT_LIGHT);
	else if (ft_strncmp(line, "C", i) == 0)
		return (PARSE_CAMERA);
	else if (ft_strncmp(line, "L", i) == 0)
		return (PARSE_LIGHT);
	else if (ft_strncmp(line, "pl", i) == 0)
		return (PARSE_PLANE);
	else if (ft_strncmp(line, "sp", i) == 0)
		return (PARSE_SPHERE);
	else if (ft_strncmp(line, "cy", i) == 0)
		return (PARSE_CYLINDER);
	printf("miniRT: wrong symbol error\n");
	return (PARSE_ERROR);
}

int	parse_double(double *f, char *str, int i)
{
	long long	is_minus;
	double		fraction;

	fraction = 1;
	is_minus = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		is_minus = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		*f *= 10;
		*f += str[i++] - '0';
	}
	if (str[i] == '.')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		fraction *= 0.1;
		*f += (str[i++] - '0') * fraction;
	}
	if (is_minus)
		*f *= -1;
	return (i);
}

int	parse_doubles(t_vec3 *vec, char *line, int idx)
{
	idx = parse_double(&(*vec).x, line, idx);
	// printf("%f,",(*vec).x);
	if (line[idx] != ',' || (('0' > line[idx + 1] || line[idx + 1] > '9') && line[idx + 1] != '-' && line[idx + 1] != '+'))
		return (0);
	idx = parse_double(&(*vec).y, line, ++idx);
	// printf("%f,",(*vec).y);
	if (line[idx] != ',' || (('0' > line[idx + 1] || line[idx + 1] > '9') && line[idx + 1] != '-' && line[idx + 1] != '+'))
		return (0);
	idx = parse_double(&(*vec).z, line, ++idx);
	// printf("%f\n",(*vec).z);
	return (idx);
}
