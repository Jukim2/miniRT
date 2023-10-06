/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:01 by kjs               #+#    #+#             */
/*   Updated: 2023/10/05 19:25:36 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>

t_vec3	rand_vec3(void)
{
	return (norm_vec3(vec3(random_double(), random_double(), random_double())));
}
