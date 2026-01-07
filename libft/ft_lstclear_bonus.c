/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:20:59 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/02 15:29:54 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*n_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		n_node = current->next;
		ft_lstdelone(current, del);
		current = n_node;
	}
	*lst = NULL;
}
