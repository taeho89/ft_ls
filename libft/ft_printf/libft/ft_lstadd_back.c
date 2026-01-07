/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:10:02 by takwak            #+#    #+#             */
/*   Updated: 2024/10/06 09:12:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;
	t_list	*parent;

	cur = *lst;
	parent = NULL;
	if (*lst == NULL)
		*lst = new;
	while (cur != NULL)
	{
		parent = cur;
		cur = cur->next;
	}
	if (parent != NULL)
		parent->next = new;
}
