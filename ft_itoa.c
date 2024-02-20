/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:39:03 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/05 16:41:58 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		i;
	long	x;

	i = 0;
	if (n < 0)
	{
		x = (long)n * (-1);
		i = 1;
	}
	else
		x = n;
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

static long	ft_signe(int n)
{
	long	x;

	if (n < 0)
		x = (long)n * -1;
	else
		x = n;
	return (x);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	x;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	x = ft_signe(n);
	i = 1;
	while (x > 0)
	{
		str[size - i++] = x % 10 + '0';
		x /= 10;
	}
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
