/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:05:36 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/13 14:05:45 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	if (del != NULL && lst != NULL)
	{
		curr = *lst;
		while (curr != NULL)
		{
			del(curr->content);
			prev = curr;
			curr = curr->next;
			free(prev);
		}
		*lst = NULL;
	}
}
