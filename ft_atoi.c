/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:29:53 by rboutaik          #+#    #+#             */
/*   Updated: 2023/12/08 15:52:25 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	long			nb;
	unsigned long	x;

	i = 0;
	signe = 1;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = x * 10 + str[i++] - 48;
		x = nb;
		if (x > 9223372036854775807 && signe == 1)
			return (-1);
		else if (x > 9223372036854775808uL && signe == -1)
			return (0);
	}
	return (x * signe);
}