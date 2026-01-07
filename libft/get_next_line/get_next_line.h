/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:51:38 by takwak            #+#    #+#             */
/*   Updated: 2024/10/28 06:51:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buf
{
	char	*buf;
	int		idx;
	int		last_flag;
}	t_buf;
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_custom(char *s1, char *s2, int size);
char	*set_buffer(char *buf);
char	*get_next_line(int fd);

#endif
