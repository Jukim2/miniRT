/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/26 14:45:53 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_engine	e;

	if (argc == 1 || is_wrong_file_name(argv[1]))
	{
		printf("Error\nCheck argument\n");
		return (0);
	}	
	init_engine(&e, argv[1]);
	execute_engine(&e);
	return (0);
}
