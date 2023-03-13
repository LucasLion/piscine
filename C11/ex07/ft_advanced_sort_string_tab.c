/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:26:03 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 14:05:19 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		tab_size;	
	char	*temp;

	i = 0;
	tab_size = 0;
	temp = 0;
	while (tab[tab_size] != 0)
		tab_size++;
	while (i < tab_size)
	{
		j = i + 1;
		while (j < tab_size)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}
