/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:25:02 by llion             #+#    #+#             */
/*   Updated: 2022/07/17 18:11:13 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	rev_index;
	int	buffer;	

	index = 0;
	rev_index = size - 1;
	while (index < size / 2)
	{
		buffer = tab[index];
		tab[index] = tab[rev_index];
		tab[rev_index] = buffer;
		index++;
		rev_index--;
	}
}
