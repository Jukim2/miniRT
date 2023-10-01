/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/01 19:26:49 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	initialize_objects(t_object *objects)
{
	ft_bzero(objects, sizeof(t_object));
	objects->cylinder = 0;
	objects->plane = 0;
	objects->sphere = 0;
}

int	main(int argc, char **argv)
{
	t_object	objects;
	
	initialize_objects(&objects);
	parse(&objects, argv[1]);
}
