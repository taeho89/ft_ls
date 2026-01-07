/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:17:34 by takwak            #+#    #+#             */
/*   Updated: 2025/04/23 22:38:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*past;

	cur = *lst;
	while (cur != NULL)
	{
		past = cur;
		cur = cur->next;
		if (del != NULL)
			del(past->content);
		free(past);
	}
	*lst = cur;
}
