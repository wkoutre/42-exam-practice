/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:19:43 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/13 21:19:58 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		w_count(const char *str)
{
	int			count;
	int			prev;

	count = 0;
	prev = 0;
	while (*str)
	{
		if ((*str == ' ' || *str == '\t' || *str == '\n') && prev == 1)
			prev = 0;
		if (*str != ' ' && *str != '\t' &&  *str != '\n' && prev == 0)
		{
			prev = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int		w_len(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static void		var_init(int *new_x, int *i, int *y)
{
	*new_x = 0;
	*y = 0;
	*i = 0;
}

static char		**end(char **a, int y)
{
	a[y] = 0;
	return (a);
}

char			**ft_split(char *s)
{
	char	**a;
	int		y;
	int		new_x;
	int		i;
	int		h;

	var_init(&new_x, &i, &y);
	if (!(s) || !(a = (char **)malloc(sizeof(char **) * (w_count(s) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n') && s[i])
		{
			h = i;
			if (!(a[y] = (char *)malloc(sizeof(char *) * (w_len(s, i) + 1))))
				return (NULL);
			while (h < (i = w_len(s, i)))
				a[y][new_x++] = s[h++];
			a[y++][new_x] = '\0';
			new_x = 0;
		}
	}
	return (end(a, y));
}
