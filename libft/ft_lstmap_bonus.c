/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:07:38 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/09 23:24:49 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*curr_node;
	t_list	*nodetodel;

	curr_node = lst;
	nodetodel = lst;
	new_list = malloc(sizeof(t_list));
	if (lst == NULL || del == NULL || f == NULL || new_list == NULL)
		return (NULL);
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
		new_list->content = f(nodetodel->content);
		del(nodetodel->content);
		free(nodetodel->content);
		nodetodel = curr_node;
		new_list->next = malloc(sizeof(t_list));
		if (new_list->next == NULL)
			return (0);
		new_list = new_list->next;
	}
	new_list->next = NULL;
	return (new_list);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	new_list = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
