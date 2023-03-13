/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:30:52 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 11:27:35 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[j]) > 0)
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
