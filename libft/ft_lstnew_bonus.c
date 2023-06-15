/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:53:29 by rlevilla          #+#    #+#             */
/*   Updated: 2022/10/17 01:00:28 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr_node;

	ptr_node = malloc(sizeof(t_list));
	if (ptr_node == NULL)
		return (NULL);
	ptr_node->content = content;
	ptr_node->next = NULL;
	return (ptr_node);
}
