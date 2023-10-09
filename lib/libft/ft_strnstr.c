/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:05:53 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 13:32:22 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_identical(const char *haystack, const char *needle, size_t limit)
{
	size_t	i;

	i = 0;
	while (i <= limit)
	{
		if (needle[i] == 0)
			return (1);
		if (haystack[i] == 0 || haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == *needle
			&& is_identical(haystack + i, needle, len - i))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
