/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/09/11 16:06:42 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/11 16:06:42 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	polish_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;
	int i;
	int j;
	char *buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buff == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		++i;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buff[j++] = last_node->buffer[i];
	buff[j] = '\0';
	clean_node->buffer = buff;
	clean_node->next = NULL;
	free_list(list, clean_node, buff);
}

char	*get_line(t_list *list)
{
	int str_len;
	char *next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_new_line(list);
	next_str = (char *)malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	list_append(t_list **list, char *buff)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last_node(*list);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buff;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int char_read;
	char *buff;

	while (!find_new_line(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buff);
			return ;
		}
		if (char_read == 0)
		{
			free(buff);
			return ;
		}
		buff[char_read] = '\0';
		list_append(list, buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list *stash[MAX_FD];
	char *line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	creat_list(&stash[fd], fd);
	if (stash[fd] == NULL)
		return (NULL);
	line = get_line(stash[fd]);
	if (!line)
	{
		polish_list(&stash[fd]);
		return (NULL);
	}
	polish_list(&stash[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
