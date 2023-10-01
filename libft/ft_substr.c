/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:54 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 11:16:26 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min_value(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (ft_strlen(s) <= start)
	{
		str = malloc(sizeof(char));
		if (str == 0)
			return (0);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (min_value(ft_strlen(s), len) + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (s[start + i] == '\0')
			break ;
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
