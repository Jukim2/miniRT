/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit_record.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:59:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 13:55:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_hit_record(t_hit_record *record)
{
	record->is_hit = FALSE;
	record->is_front = -1;
	record->t = 1000000000;
	record->point = vec3(0, 0, 0);
	record->normal = vec3(0, 0, 0);
	record->rgb = vec3(0, 0, 0);
}
