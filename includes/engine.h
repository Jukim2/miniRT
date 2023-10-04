/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:17:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 12:01:02 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx.h"
# include "object.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

typedef struct s_image
{
	void			*ptr;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_objects	objects;
	t_image		img;
}	t_engine;

int		init_engine(t_engine *engine, char *config);
void	execute_engine(t_engine *engine);

#endif