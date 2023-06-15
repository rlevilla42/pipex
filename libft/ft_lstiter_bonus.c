/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:46:51 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/09 21:56:44 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;;
	}
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		next = lst->next;
		f(lst->content);
		lst = next;
	}
}
