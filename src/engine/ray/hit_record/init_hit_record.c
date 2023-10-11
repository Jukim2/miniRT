/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit_record.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:59:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 01:26:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_hit_record(t_hit_record *record)
{
	record->is_hit = FALSE;
	record->t = 1000000000;
	record->hit_shape = 0;
	record->color = vec3(0, 0, 0);
	record->point = vec3(0, 0, 0);
	record->normal = vec3(0, 0, 0);
}
