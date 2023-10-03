/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:21:53 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 21:25:59 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include "vector3.h"
#include <stdio.h> // test

int	parse_id(t_objects *objects, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (ft_strncmp(line, "A", i) == 0)
		return (AMBIENT_LIGHT);
	else if (ft_strncmp(line, "C", i) == 0)
		return (CAMERA);
	else if (ft_strncmp(line, "L", i) == 0)
		return (LIGHT);
	else if (ft_strncmp(line, "pl", i) == 0)
		return (PLANE);
	else if (ft_strncmp(line, "sp", i) == 0)
		return (SPHERE);
	else if (ft_strncmp(line, "cy", i) == 0)
		return (CYLINDER);
	else
		return (ERROR);
}

// int	parse_rgb(t_vector3 *, char *line, int idx)
// {
// 	idx = parse_int(&rgb[0], line, idx);
// 	if (line[idx] != ',' || !line[idx + 1])
// 		return (0);
// 	idx = parse_int(&rgb[1], line, ++idx);
// 	if (line[idx] != ',' || !line[idx + 1])
// 		return (0);
// 	idx = parse_int(&rgb[2], line, ++idx);
// 	return (idx);
// }

// int	parse_int(int *n, char *line, int idx)
// {
// 	int	is_minus;

// 	*n = 0;
// 	is_minus = 0;
// 	while (line[idx] == ' ')
// 		idx++;
// 	if (line[idx] == '+' || line[idx] == '-')
// 		is_minus = line[idx++] - '+';
// 	while ('0' <= line[idx] && line[idx] <= '9')
// 	{
// 		*n *= 10;
// 		*n += line[idx++] - '0';
// 	}
// 	if (is_minus)
// 		*n *= -1;
// 	return (idx);
// }


int	parse_double(double *f, char *str, int i)
{
	long long	is_minus;
	int			fraction;

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

int	parse_doubles(t_vector3 *vec, char *line, int idx)
{
	idx = parse_double(&(*vec).x, line, idx);
	// printf("%f,",floats[0]);
	if (line[idx] != ',' || ('0' > line[idx + 1] || line[idx + 1] > '9'))
		return (0);
	idx = parse_double(&(*vec).y, line, ++idx);
	// printf("%f,",floats[1]);
	if (line[idx] != ',' || ('0' > line[idx + 1] || line[idx + 1] > '9'))
		return (0);
	idx = parse_double(&(*vec).z, line, ++idx);
	// printf("%f\n",floats[2]);
	return (idx);
}
