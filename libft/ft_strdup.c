/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:01:37 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/11 15:22:28 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		idx;
	int		len;
	char	*str;

	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	str = malloc(len * sizeof(char) + 1);
	if (str == 0)
		return (0);
	idx = 0;
	while (s1[idx] != '\0')
	{
		str[idx] = s1[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
