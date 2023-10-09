/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:32:37 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/09 17:08:44 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*str;

	value = (unsigned char) c;
	str = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str[i++] = value;
	}
	return (str);
}
