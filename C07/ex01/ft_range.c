/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:31:39 by llion             #+#    #+#             */
/*   Updated: 2022/07/27 14:11:41 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	while (max > min)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
