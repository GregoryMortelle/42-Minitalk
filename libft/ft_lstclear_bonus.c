/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:17:57 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/18 17:56:43 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*first;

	if (!lst || !del)
		return ;
	first = *lst;
	while (first)
	{
		tmp = first->next;
		del(first->content);
		free(first);
		first = tmp;
	}
	*lst = NULL;
}
