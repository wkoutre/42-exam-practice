/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 20:52:20 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/13 20:52:25 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int 	hold;

	i = 0;
	while (i < size)
	{
		if (size - i == 1)
			return ;
		if (tab[i] <= tab [i + 1])
		{
			i++;
		}
		else
		{
			hold = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = hold;
			i = 0;
		}
	}
}
