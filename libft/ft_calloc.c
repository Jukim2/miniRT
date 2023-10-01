/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:44:46 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/11 15:22:15 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		ptr[i++] = 0;
	}
	return (ptr);
}
