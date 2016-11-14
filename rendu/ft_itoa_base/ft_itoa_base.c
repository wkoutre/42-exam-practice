/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:46:43 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/12 12:46:45 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int i, int base, char *new)
{
	int		negative;

	negative = 0;
	if (i < 0)
	{
		negative = 1;
		i = i * -1;
	}
	if (i >= base)
	{
		ft_putnbr(i % base, base, new++);
		ft_putnbr(i / base, base, new++);
	}
	if (i < base)
	{
		if (negative == 1 && base == 10)
		{
			*new = '-';
		}
		if (i >= 0 && i <= 9)
		{
			*new = i + 48;
		}
		else
		{
			*new = i + 55;
		}
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

char		*ft_itoa_base(int value, int base)
{
	char	*new;
	char 	*rev_new;
	int 	i;
	int		len;
	int		negative;
	char 	*min;

	min = "-2147483648";
	i = 0;
	len = 0;
	negative = 0;
	if (value < 0)
		negative = 1;
	if ((value > 2147483647 || value < -2147483648) && base == 10)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * 2048)))
		return (NULL);	
	if (value == -2147483648 && negative == 1)
	{
		while (i < ft_strlen(min))
		{
			new[i] = min[i];
			i++;
		}
		return (new);
	}
	ft_putnbr(value, base, new);
	if (!(rev_new = (char *)malloc(sizeof(ft_strlen(new) + 1))))
		return (NULL);
	while (new[i])
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (negative == 1 && base == 10)
		{
			rev_new[len] = '-';
			len++;
			negative = 0;
		}

		rev_new[len] = new[i];
		i--;
		len++;
	}
	rev_new[len] = '\0';
	return (rev_new);
}
