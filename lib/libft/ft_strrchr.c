/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:17:32 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/09 17:05:40 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*location;
	char	target;

	location = 0;
	target = (char) c;
	while (*s != '\0')
	{
		if (*s == target)
			location = (char *)s;
		s++;
	}
	if (target == '\0')
	{
		location = (char *)s;
	}
	return (location);
}
