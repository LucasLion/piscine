/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:20:02 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 11:26:26 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc((length) * sizeof(int));
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
