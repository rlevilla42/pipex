/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:34:22 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/04 03:58:44 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_node;

	curr_node = *lst;
	if (lst == NULL || inew == NULL)
		return (NULL);
	if (*lst == NULL)
		*lst = new;
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
	}
	curr_node->next = new;
	new->next = NULL;
}
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL && new != NULL)
		*lst = new;
	else if (new && lst)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
