/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:05:17 by llion             #+#    #+#             */
/*   Updated: 2022/08/02 13:20:01 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	j = 0;
	while (j < size - 1)
	{
		i = j + 1;
		min = tab[j];
		while (i < size)
		{
			if (tab[i] < min)
			{
				min = tab[i];
				tab[i] = tab[j];
				tab[j] = min;
			}
			i++;
		}
		j++;
	}
	return (*tab);
}
