/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:02:19 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/11 12:02:21 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
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

int word_counter(char *str)
{
	int word;
	int prev;

	word = 0;
	prev = 0;
	while (*str)
	{
		if (!(is_space(*str)) && prev == 0)
		{
			str++;
			prev = 1;
			word++;
		}
		if (!(is_space(*str)) && prev == 1)
		{
			str++;
		}
		if (is_space(*str) && prev == 1)
		{
			str++;
			prev = 0;
		}
		if (is_space(*str) && prev == 0)
		{
			str++;
		}
	}
	return (word);
}

char	**rev_wstr(char *str)
{
	int i;
	int j;
	int k;
	int x;
	int words;
	char **new;

	i = 0;
	j = 0;
	x = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (words = word_counter(str)) + 1)))
		return (NULL);
	while (words > 0)
	{
		while (is_space(str[i]) && str[i])
		{
			i++;
		}
		k = i;
		while (!(is_space(str[i])) && str[i])
		{
			i++;
			j++;
		}
		if (!(new[x] = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		j = 0;
		while (k < i)
		{
			new[x][j] = str[k];
			k++;
			j++;
		}
		new[x][j] = '\0';
		x++;
		j = 0;
		words--;
	}
	if (!(new[x] = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	new[x][j] = '\0';
	return (new);
}

int main(int argc, char **argv)
{
	int i;
	char **ptr;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		i = word_counter(argv[1]);
		ptr = rev_wstr(argv[1]);
		while (i > 0)
		{
			ft_putstr(ptr[--i]);
			if (i > 0)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
/*"Nick Boo"
i = 8;*/