/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:41:56 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/12 11:42:10 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		word_count(char *str)
{
	int count;
	int prev;

	count = 0;
	prev = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str && prev == 0)
		{
			str++;
			count++;
			prev = 1;
		}
		if (*str != ' ' && *str != '\t' && *str && prev == 1)
			str++;

		if ((*str == ' ' || *str == '\t') && *str && prev == 1)
		{
			str++;
			prev = 0;
		}
		if ((*str == ' ' || *str == '\t') && *str && prev == 0)
		{
			str++;
		}
	}
	return (count);
}

int		word_length(char *str)
{
	int h;

	h = 0;
	if (*str)
	{
		while ((*str == ' ' || *str == '\t') && *str)
			str++;
		while (*str != ' ' && *str != '\t' && *str)
		{
			str++;
			h++;
		}
	}
	return (h);
}

char	**rostring(char *str)
{
	char **new;
	int x;
	int y;
	int words;

	x = 0;
	y = 0;
	words = word_count(str);
	if (!(new = (char **)malloc(sizeof(char *) * (word_count(str) + 1))))
		return (NULL);
	while (words > 0)
	{
		while ((*str == ' ' || *str == '\t') && *str)
			str++;
		if (*str != ' ' && *str != '\t' && *str)
		{
			if (!(new[y] = (char *)(malloc(sizeof(char) * (word_length(str) + 1)))))
				return (NULL);
			while ((*str != ' ' && *str != '\t') && *str)
			{
				new[y][x] = *str;
				str++;
				x++;
			}
			new[y][x] = '\0';
			y++;
			x = 0;
			words--;
		}
	}
	if (!(new[y] = (char *)(malloc(sizeof(char) * (word_length(str) + 1)))))
		return (NULL);
	new[y][x] = 0;
	return (new);
}

int	main(int argc, char **argv)
{
	int i;
	char **new;
	int	words;
	
	i = 1;
	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		words = word_count(argv[1]);
		new = rostring(argv[1]);
		while (i < words)
		{
			ft_putstr(new[i]);
			i++;
			ft_putchar(' ');
		}
		ft_putstr(new[0]);
		ft_putchar('\n');
	}
}
