/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:24:58 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 18:28:42 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		if (((unsigned char)s[i] != (unsigned char)s2[i])
			|| ((unsigned char)s[i] == '\0' && (unsigned char)s2[i] == '\0'))
			return ((unsigned char)s[i] - (unsigned char)s2[i]);
	}
	return (0);
}
