/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:27:00 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 13:02:31 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

char	*get_next_line(int fd)
{
	t_file			*file;
	char			*buf;
	char			*str;
	static t_file	*file_list;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (!find_file(fd, file_list) && !make_file_node(fd, &file_list))
	{
		free(buf);
		return (0);
	}
	file = find_file(fd, file_list);
	str = read_file(fd, buf, file);
	if (find_newline(0, str) == -1)
		free_all(buf, file->line, file, &file_list);
	return (str);
}

char	*read_file(int fd, char *buf, t_file *file)
{
	int		rbyte;
	char	*str;
	t_line	*line;

	line = file->line;
	while (find_newline(0, line->str) == -1)
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == 0)
			return (line->str);
		if (rbyte < 0 || !make_line(rbyte, line, buf))
		{
			if (line->str)
				free (line->str);
			return (0);
		}
	}
	file->line = line->next_line;
	if (!file->line)
		make_line_node(file);
	str = line->str;
	free_all(buf, line, 0, 0);
	return (str);
}

int	make_line(int rbyte, t_line *line, char *buf)
{
	int	start;
	int	end;
	int	len;

	buf[rbyte] = 0;
	len = 0;
	while (buf[len])
		len++;
	end = find_newline(0, buf);
	if (end != -1)
		line->str = ft_strnjoin(line->str, buf, 0, end);
	else
		line->str = ft_strnjoin(line->str, buf, 0, len);
	while (line->str && end != -1)
	{
		start = end + 1;
		end = find_newline(start, buf);
		if (end == -1 && len > start && !push_line(line, buf, start, len - 1))
			return (0);
		else if (end != -1 && !push_line(line, buf, start, end))
			return (0);
	}
	if (!line->str)
		return (0);
	return (1);
}

int	push_line(t_line *line, char *buf, int start, int end)
{
	char	*str;
	t_line	*new_line;
	int		idx;

	idx = 0;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	while (start != end + 1)
		str[idx++] = buf[start++];
	str[idx] = '\0';
	new_line = malloc(sizeof(t_line));
	if (!new_line)
		return (0);
	new_line->next_line = 0;
	new_line->str = str;
	while (line->next_line)
		line = line->next_line;
	line->next_line = new_line;
	new_line->prev_line = line;
	return (1);
}

void	free_all(char *buf, t_line *line, t_file *file, t_file **file_list)
{
	free(line);
	free(buf);
	if (file)
	{
		if (file->prev_file && file->next_file)
		{
			file->prev_file->next_file = file->next_file;
			file->next_file->prev_file = file->prev_file;
		}
		else if (file->next_file)
		{
			file->next_file->prev_file = 0;
			*file_list = file->next_file;
		}
		else if (file->prev_file)
			file->prev_file->next_file = 0;
		else
			*file_list = 0;
		free(file);
	}
}
