/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:28:27 by llion             #+#    #+#             */
/*   Updated: 2022/08/01 14:52:49 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;
	int	endstr;

	endstr = '\0';
	count = 0;
	while (*str != endstr)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(src) + 1) * sizeof(src));
	if (ptr == 0)
		return (0);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = malloc(sizeof(*tab) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].size = ft_strlen(av[i]);
		i++;
	}
	tab[i].str = 0;
	tab[i].copy = 0;
	tab[i].size = 0;
	return (tab);
}
