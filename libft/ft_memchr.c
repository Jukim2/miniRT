/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:47:56 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/09 17:04:07 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	target;

	i = 0;
	str = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == target)
			return (str + i);
		i++;
	}
	return (0);
}
