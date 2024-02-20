/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:46:03 by rboutaik          #+#    #+#             */
/*   Updated: 2023/11/12 17:22:45 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_existe(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_size(char const *s, char const *set, int tsize)
{
	int	start;
	int	end;

	start = 0;
	while (s[start] && ft_existe(s[start], set))
		start++;
	end = tsize - 1;
	while (end > 0 && s[end] && ft_existe(s[end], set))
		end--;
	return (end - start + 1);
}

static int	ft_iter(char const *s1, char const *set, int add, int str)
{
	int	i;

	i = 0;
	if (add == 1)
	{
		i = str;
		while (s1[i] && ft_existe(s1[i], set))
			i++;
	}
	else if (add == 0)
	{
		i = str;
		while (s1[i] && ft_existe(s1[i], set))
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;
	int		i;

	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	i = ft_size(s1, set, end);
	if (end == i)
		return (ft_strdup(s1));
	if (i <= 0)
		return (ft_strdup(""));
	new = (char *)malloc((i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	start = ft_iter(s1, set, 1, 0);
	end = ft_iter(s1, set, 0, end - 1);
	i = 0;
	while (start <= end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
