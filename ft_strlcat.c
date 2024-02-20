/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:06:10 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/13 14:07:41 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dsts;
	size_t	srcs;

	i = 0;
	dsts = 0;
	srcs = 0;
	while (src[srcs])
		srcs++;
	if (dst == NULL && dstsize == 0)
		return (srcs);
	while (dst[dsts])
		dsts++;
	if (dsts >= dstsize)
		return (srcs + dstsize);
	while (i < dstsize - dsts - 1 && src[i])
	{
		dst[i + dsts] = src[i];
		i++;
	}
	dst[i + dsts] = '\0';
	return (dsts + srcs);
}
