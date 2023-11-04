/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:49 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 00:30:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_file	*find_file(int fd, t_file *file_list)
{
	while (file_list)
	{
		if (file_list->fd == fd)
			return (file_list);
		file_list = file_list->next_file;
	}
	return (0);
}

int	make_file_node(int fd, t_file **file_list)
{
	t_file	*new_file;
	t_file	*file;

	new_file = malloc(sizeof(t_file));
	if (!new_file)
		return (0);
	new_file->fd = fd;
	new_file->next_file = 0;
	new_file->prev_file = 0;
	if (!make_line_node(new_file))
		return (0);
	if (!(*file_list))
	{
		(*file_list) = new_file;
		return (1);
	}
	file = *file_list;
	while (file->next_file)
		file = file->next_file;
	file->next_file = new_file;
	new_file->prev_file = file;
	return (1);
}

int	make_line_node(t_file *file)
{
	file->line = malloc(sizeof(t_line));
	if (!file->line)
		return (0);
	file->line->str = 0;
	file->line->next_line = 0;
	file->line->prev_line = 0;
	return (1);
}

int	find_newline(int idx, char *buffer)
{
	if (!buffer)
		return (-1);
	while (buffer[idx])
	{
		if (buffer[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*ft_strnjoin(char *str1, char *str2, int start_idx, int end_idx)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str1 && str1[i])
		i++;
	str = malloc(sizeof(char) * (i + end_idx - start_idx + 2));
	if (!str)
		return (0);
	j = 0;
	while (str1 && str1[j])
	{
		str[j] = str1[j];
		j++;
	}
	while (start_idx != end_idx + 1)
		str[j++] = str2[start_idx++];
	str[j] = '\0';
	if (str1)
		free(str1);
	return (str);
}
