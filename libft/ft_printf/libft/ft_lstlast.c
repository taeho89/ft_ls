/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:09:00 by takwak            #+#    #+#             */
/*   Updated: 2024/10/06 09:09:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*past;

	if (lst == NULL)
		return (NULL);
	past = lst;
	while (lst != NULL)
	{
		past = lst;
		lst = lst->next;
	}
	return (past);
}
