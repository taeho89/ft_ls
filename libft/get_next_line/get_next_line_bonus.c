/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:59:47 by takwak            #+#    #+#             */
/*   Updated: 2024/12/11 16:42:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin_custom(char *s1, char *s2, int s2_len)
{
	char	*new;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (*(s1 + s1_len) != '\0')
		s1_len++;
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			*(new + i) = *(s1 + i);
		else
			*(new + i) = *(s2 + i - s1_len);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

static char	*make_line(char *res, t_buffer *info, int size)
{
	char	*new_res;

	if (res == NULL)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		*res = '\0';
	}
	new_res = ft_strjoin_custom(res, info->buf + info->idx, size);
	if (new_res == NULL)
		return (NULL);
	free(res);
	return (new_res);
}

static int	exist_line(char **res, t_buffer *info)
{
	int		len;
	char	*start_adr;

	if (info->last)
	{
		start_adr = info->buf + info->idx;
		if (ft_gnl_strchr(start_adr, '\n') != NULL)
		{
			len = ft_gnl_strchr(start_adr, '\n') + 1 - start_adr;
			*res = make_line(*res, info, len);
			info->idx += len;
			if (*(start_adr + len) == '\0')
				init_(info, 2);
			return (1);
		}
		else
		{
			*res = make_line(*res, info, BUFFER_SIZE - info->idx);
			init_(info, 2);
		}
	}
	return (0);
}

static void	*end_read(t_buffer **list, char *res, int fd, int read_size)
{
	if (read_size == -1)
	{
		if (res != NULL)
		{
			free(res);
			return (NULL);
		}
		return (free_lst(list, fd));
	}
	if (res != NULL)
		return (res);
	return (free_lst(list, fd));
}

char	*get_next_line(int fd)
{
	static t_buffer	*info;
	t_buffer		*list;
	char			*res;
	int				read_size;

	res = NULL;
	if (info == NULL)
		info = ft_gnl_newlst(&info, info, fd);
	list = info;
	while (list != NULL && list->label != fd)
		list = list->next;
	if (list == NULL)
		list = ft_gnl_newlst(&info, list, fd);
	if (exist_line(&res, list))
		return (res);
	read_size = read(fd, list->buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		list->idx = 0;
		list->last = 1;
		if (exist_line(&res, list))
			return (res);
		read_size = read(fd, list->buf, BUFFER_SIZE);
	}
	return (end_read(&info, res, fd, read_size));
}
