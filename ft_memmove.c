/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:38:24 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/06 09:05:48 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ds;
	char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (ds == NULL && src == NULL)
		return (NULL);
	if (ds < sr)
	{
		i = -1;
		while (++i < len)
			ds[i] = sr[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			len--;
			ds[len] = sr[len];
		}
	}
	return (dst);
}
