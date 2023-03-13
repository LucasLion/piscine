/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:35:16 by llion             #+#    #+#             */
/*   Updated: 2022/07/28 12:17:07 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	int				*tab;
	unsigned int	len;

	len = max - min;
	i = 0;
	if (min >= max)
		return (0);
	tab = malloc((len) * sizeof(int));
	*range = tab;
	if (tab == 0)
		return (-1);
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (len);
}
