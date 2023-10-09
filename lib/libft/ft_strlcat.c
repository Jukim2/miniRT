/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:05:58 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/09 13:23:05 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize > len_dest)
	{
		while (i < (dstsize - len_dest - 1) && src[i] != '\0')
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
		return (len_dest + len_src);
	}
	return (len_src + dstsize);
}
