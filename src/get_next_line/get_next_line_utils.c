/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:30:12 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/11 16:30:12 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_last_node(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	len_new_line(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				return (len + 1);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

int	find_new_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buffer[i] && i < BUFFER_SIZE)
		{
			if (list->buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL || str == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			str[j] = list->buffer[i];
			j++;
			if (list->buffer[i] == '\n')
			{
				str[j] = '\0';
				return ;
			}
			i++;
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	free_list(t_list **list, t_list *clean_node, char *buff)
{
	t_list	*current;

	if (*list == NULL)
		return ;
	while (*list)
	{
		current = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = current;
	}
	*list = NULL;
	if (clean_node->buffer[0])
		*list = clean_node;
	else
	{
		free(buff);
		free(clean_node);
	}
}
