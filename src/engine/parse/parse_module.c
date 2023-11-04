/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:21:53 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 01:13:50 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include "numft.h"

int	parse_id(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (i == 0)
		return (PARSE_ERROR);
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
	if (((line[idx] == '-' || line[idx] == '+') \
		&& ('0' > line[idx + 1] || line[idx + 1] > '9')) \
		|| ((line[idx] != '-' && line[idx] != '+') \
		&& ('0' > line[idx] || line[idx] > '9')))
		return (0);
	idx = parse_double(&(*vec).x, line, idx);
	if (line[idx] != ',' || ((line[idx + 1] == '-' || line[idx + 1] == '+') \
		&& ('0' > line[idx + 2] || line[idx + 2] > '9')) || \
		((line[idx + 1] != '-' && line[idx + 1] != '+') \
		&& ('0' > line[idx + 1] || line[idx + 1] > '9')))
		return (0);
	idx = parse_double(&(*vec).y, line, ++idx);
	if (line[idx] != ',' || ((line[idx + 1] == '-' || line[idx + 1] == '+') \
		&& ('0' > line[idx + 2] || line[idx + 2] > '9')) || \
		((line[idx + 1] != '-' && line[idx + 1] != '+') \
		&& ('0' > line[idx + 1] || line[idx + 1] > '9')))
		return (0);
	idx = parse_double(&(*vec).z, line, ++idx);
	return (idx);
}
