/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:17:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/03 22:41:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx.h"
# include "object.h"

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