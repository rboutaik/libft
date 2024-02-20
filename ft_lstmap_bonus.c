/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:14:48 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/13 14:01:07 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*list;
	t_list	*h;

	list = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		h = malloc(sizeof(t_list));
		if (h == NULL)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		h->content = f(lst->content);
		h->next = NULL;
		ft_lstadd_back(&list, h);
		lst = lst->next;
	}
	return (list);
}
