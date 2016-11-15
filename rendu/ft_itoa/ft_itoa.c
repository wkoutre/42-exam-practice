/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:51:41 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/14 18:51:54 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_putnbr(int value, char *str)
{
	if (value > 9)
	{
		ft_putnbr(value % 10, str++);
		ft_putnbr(value / 10, str++);
	}
	if (value <= 9)
	{
		*str = value + 48;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int 	i;
	int		negative;
	char	*rev;
	int		len;
	int		h;

	i = 0;
	negative = 0;
	if (!(str = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	while (i < 11)
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	if (nbr == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	if (nbr < -2147483648 || nbr > 2147483647)
		return (NULL);
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	ft_putnbr(nbr, str);
	len = ft_strlen(str);
	h = len;
	if (negative == 1)
	{
		if (!(rev = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		rev[i] = '-';
		i++;
		while (i <= h)
		{
			rev[i] = str[len - 1];
			i++;
			len--;
		}
	}
	else
	{
		if (!(rev = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < h)
		{
			rev[i] = str[len - 1];
			i++;
			len--;
		}
	}
	rev[i] = '\0';
	return (rev);
}
