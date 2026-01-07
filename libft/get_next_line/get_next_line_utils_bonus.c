/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:11:00 by takwak            #+#    #+#             */
/*   Updated: 2024/12/11 16:40:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	init_(t_buffer *list, int type)
{
	int	i;

	if (type == 1)
	{
		list->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (list->buf == NULL)
			return (0);
		i = 0;
		while (i <= BUFFER_SIZE)
			list->buf[i++] = '\0';
		list->last = 0;
		list->idx = 0;
		list->next = NULL;
	}
	else if (type == 2)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
			list->buf[i++] = '\0';
		list->last = 0;
		list->idx = 0;
	}
	return (1);
}

t_buffer	*ft_gnl_newlst(t_buffer **list, t_buffer *new_list, int fd)
{
	t_buffer	*cur;

	if (*list == NULL)
	{
		*list = (t_buffer *)malloc(sizeof(t_buffer));
		if (*list == NULL)
			return (NULL);
		init_(*list, 1);
		(*list)->label = fd;
		return (*list);
	}
	cur = *list;
	while (cur->next != NULL)
		cur = cur->next;
	new_list = (t_buffer *)malloc(sizeof(t_buffer));
	if (new_list == NULL)
		return (NULL);
	init_(new_list, 1);
	new_list->label = fd;
	cur->next = new_list;
	return (new_list);
}

void	*free_lst(t_buffer **lst, int fd)
{
	t_buffer	*past;
	t_buffer	*cur;
	t_buffer	*freed;

	cur = *lst;
	if (cur->label == fd)
	{
		*lst = cur->next;
		free(cur->buf);
		cur->buf = NULL;
		free(cur);
		cur = NULL;
		return (NULL);
	}
	while (cur->label != fd)
	{
		past = cur;
		cur = cur->next;
	}
	freed = cur;
	cur = cur->next;
	past->next = cur;
	free(freed->buf);
	free(freed);
	return (NULL);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
