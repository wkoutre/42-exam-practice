/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:10:16 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/11 11:10:18 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	epur_str(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		i++;
	}
	while (is_space(str[i - 1]))
		i--;
	while (is_space(*str))
	{
		str++;
		i--;
	}
	while (*str && i > 0)
	{
		while (!(is_space(*str)) && i > 0)
		{
			ft_putchar(*str);
			str++;
			i--;
		}
		while (is_space(*str) && i > 0)
		{
			str++;
			i--;
		}
		if (*str && i > 0)
		{
			ft_putchar(' ');
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
	}
	else
	{
		epur_str(argv[1]);
		ft_putchar('\n');
	}
}
