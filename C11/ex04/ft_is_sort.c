/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:07:29 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 11:25:07 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))

{
	int	i;	
	int	boolean;

	i = 0;
	boolean = 1;
	while (i < length - 1 && boolean)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			boolean = 0;
		i++;
	}
	if (boolean == 1)
		return (1);
	i = 0;
	boolean = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
