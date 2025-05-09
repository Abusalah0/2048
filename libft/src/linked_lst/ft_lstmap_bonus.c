/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:13 by abdsalah          #+#    #+#             */
/*   Updated: 2024/10/21 02:03:53 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*add_mapped_node(t_list **head, void *(*f)(void *),
		void (*del)(void *), void *content)
{
	void	*new_content;
	t_list	*new_node;

	new_content = f(content);
	if (new_content == NULL)
	{
		ft_lstclear(head, del);
		return (NULL);
	}
	new_node = ft_lstnew(new_content);
	if (new_node == NULL)
	{
		del(new_content);
		ft_lstclear(head, del);
		return (NULL);
	}
	ft_lstadd_back(head, new_node);
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		if (add_mapped_node(&head, f, del, lst->content) == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (head);
}
