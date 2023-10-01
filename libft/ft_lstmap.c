/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:01 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 17:31:29 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(t_list *head, void (*del)(void *))
{
	t_list	*node;

	while (head)
	{
		node = head -> next;
		del(head -> content);
		free(head);
		head = node;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*n_node;

	if (lst == 0)
		return (0);
	n_node = ft_lstnew(f(lst -> content));
	if (n_node == 0)
		return (0);
	head = n_node;
	while (lst -> next != 0)
	{
		lst = lst -> next;
		n_node = ft_lstnew(f(lst -> content));
		if (n_node == 0)
		{
			free_lst(head, del);
			return (0);
		}
		ft_lstadd_back(&head, n_node);
	}
	return (head);
}
