/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:49 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/14 17:03:51 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** REMEMBER TO INITIALIZE ALL INDICES OF THE NEW STRING TO 0!!!!
*/

#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr(int value, int base, char *str)
{
	if (value >= base)
	{
		ft_putnbr(value % base, base, str++);
		ft_putnbr(value / base, base, str++);
	}
	else
	{
		if (value >= 0 && value <= 9)
		{
			*str = value + 48;
		}
		else
		{
			*str = value + 55;
		}
	}
}

int		ft_strlen(char *str)
{
	int	 i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	int 	negative;
	char	*min;
	char	*num;
	int 	i;
	char	*rev;
	int		len;

	negative = 0;
	i = 0;
	min = "-2147483648";

	if (value < 0)
	{
		if (base == 10)
			negative = 1;
		value *= -1;
	}
	if (value == -2147483648)
	{
		if (!(num = (char *)malloc(sizeof(char) * 31)))
			return (NULL);
		while (min[i])
		{
			num[i] = min[i];
			i++;
		}
		num[i] = '\0';
		return (num);
	}
	if (value > 2147483647 || value < -2147483648)
		return (NULL);
	if (!(num = (char *)malloc(sizeof(char) * 31)))
		return (NULL);
	i = 0;
	while (i < 31)
	{
		num[i] = 0;
		i++;
	}
	ft_putnbr(value, base, num);
	i = 0;
	len = ft_strlen(num);
	while (*num)
		num++;
	num--;
	if (negative == 1)
	{
		if (!(rev = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		rev[i] = '-';
		i++;
		while (i < len + 1)
		{
			rev[i] = *num;
			i++;
			num--;
		}
	}
	else
	{
		if (!(rev = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		while (i < len)
		{
			rev[i] = *num;
			i++;
			num--;
		}
	}
	rev[i] = '\0';
	return (rev);
}
