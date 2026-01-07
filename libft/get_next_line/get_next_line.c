/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:14 by takwak            #+#    #+#             */
/*   Updated: 2024/10/28 10:19:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_line(char *res, char *buf, int size)
{
	char	*new_res;

	if (res == NULL)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		*res = '\0';
	}
	new_res = ft_strjoin_custom(res, buf, size);
	if (new_res == NULL)
		return (NULL);
	free(res);
	return (new_res);
}

static int	exist_line(char **res, char *buf, int *idx, int *last_flag)
{
	int	len;

	if (*last_flag != 0)
	{
		if (ft_strchr(buf + *idx, '\n') != NULL)
		{
			len = ft_strchr(buf + *idx, '\n') + 1 - (buf + *idx);
			*res = make_line(*res, buf + *idx, len);
			*idx += len;
			if (*(buf + *idx) == '\0')
			{
				*last_flag = 0;
				*idx = 0;
			}
			return (1);
		}
		else
		{
			*res = make_line(*res, buf + *idx, BUFFER_SIZE - *idx);
			*idx = 0;
			*last_flag = 0;
			return (0);
		}
	}
	return (0);
}

static void	*read_end(char **buf, char *res, int read_size)
{
	if (read_size == -1)
	{
		if (res != NULL)
		{
			free(*buf);
			*buf = NULL;
			free(res);
			return (NULL);
		}
	}
	if (res != NULL)
		return (res);
	free(*buf);
	*buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_buf	info;
	char			*res;
	int				read_size;

	res = NULL;
	info.buf = set_buffer(info.buf);
	if (exist_line(&res, info.buf, &info.idx, &info.last_flag))
		return (res);
	read_size = read(fd, info.buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		info.idx = 0;
		info.last_flag = 1;
		if (read_size < BUFFER_SIZE)
			info.buf[read_size] = '\0';
		if (exist_line(&res, info.buf, &info.idx, &info.last_flag))
			return (res);
		read_size = read(fd, info.buf, BUFFER_SIZE);
	}
	return (read_end(&info.buf, res, read_size));
}
