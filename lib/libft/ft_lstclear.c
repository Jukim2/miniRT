/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:22:35 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 17:28:39 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pre_node;
	t_list	*post_node;

	if (*lst == 0)
		return ;
	pre_node = *lst;
	while (pre_node)
	{
		post_node = pre_node -> next;
		del(pre_node->content);
		free(pre_node);
		pre_node = post_node;
	}
	*lst = 0;
}
