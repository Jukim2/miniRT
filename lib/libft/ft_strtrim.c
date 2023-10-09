/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:22:25 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/11 19:38:41 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char ch, char const *set)
{
	while (*set != '\0')
	{
		if (*set == ch)
			return (1);
		set++;
	}
	return (0);
}

static void	count_valid_ch(char const *s1, char const *set, int start_end[2])
{
	int	begin;
	int	end;

	end = 0;
	begin = 0;
	while (s1[end] != '\0')
		end++;
	while (is_in_set(s1[begin], set))
	{
		begin++;
		if (begin == end)
		{
			start_end[0] = begin;
			start_end[1] = end;
			return ;
		}
	}
	while (is_in_set(s1[end - 1], set))
	{
		end--;
	}
	start_end[0] = begin;
	start_end[1] = end;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_end[2];
	int		i;
	char	*str;

	count_valid_ch(s1, set, start_end);
	str = malloc(sizeof(char) * start_end[1] - start_end[0] + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (start_end[0] + i != start_end[1])
	{
		str[i] = s1[start_end[0] + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
