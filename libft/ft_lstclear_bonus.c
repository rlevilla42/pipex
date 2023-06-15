/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:16:55 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/09 21:43:55 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;

	curr_node = *lst;
	if (*lst == NULL || del == NULL)
		return ;
	while (curr_node != NULL)
	{
		del(curr_node->content);
		free(curr_node);
		curr_node = curr_node->next;
		// faux la derniere ligne car *lst a ete free a ce moment la
	}
	*lst = NULL;
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;

	curr_node = *lst;
	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		curr_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = curr_node;
	}
	*lst = NULL;
}

/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (*lst && del)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next;
		}
		*lst = NULL;
	}
}*/
