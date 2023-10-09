/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/09 14:41:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	main(int argc, char **argv)
{
	t_engine	e;

	(void)argc;
	init_engine(&e, argv[1]);
	execute_engine(&e);
	return (0);
}
