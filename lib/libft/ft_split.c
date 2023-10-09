/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:11:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 13:02:16 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;
	int	word_finder;

	count = 0;
	word_finder = 1;
	while (*str)
	{
		if (word_finder && *str != c)
		{
			count++;
			word_finder = 0;
		}
		if (*str == c)
			word_finder = 1;
		str++;
	}
	return (count);
}

static char	*make_str(const char *str, char c)
{
	int		len;
	int		idx;
	char	*word;

	len = 0;
	while (str[len] != c && str[len] != '\0')
	{
		len++;
	}
	word = (char *)malloc(sizeof(char) * len + sizeof(char));
	if (word == 0)
		return (0);
	idx = -1;
	while (++idx < len)
	{
		word[idx] = str[idx];
	}
	word[idx] = '\0';
	return (word);
}

static void	free_arr(char **arr, int arr_idx)
{
	int	i;

	i = 0;
	while (i < arr_idx)
	{
		free(arr[i++]);
	}
	free(arr);
}

char	**ft_split(char const *str, char c)
{
	int		word_finder;
	int		arr_idx;
	char	**arr;

	word_finder = 1;
	arr_idx = 0;
	arr = (char **)ft_calloc(word_count(str, c) + 1, sizeof(char *));
	if (arr == 0)
		return (0);
	while (*str)
	{
		if (word_finder-- == 1 && *str != c)
		{
			arr[arr_idx] = make_str(str, c);
			if (arr[arr_idx++] == 0)
			{
				free_arr(arr, arr_idx - 1);
				return (0);
			}
		}
		if (*str == c)
			word_finder = 1;
		str++;
	}
	return (arr);
}
