/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:48:19 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 13:56:13 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	cpy_len;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	cpy_len = dstsize - 1;
	while (cpy_len-- > 0)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
