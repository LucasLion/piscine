/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:45:36 by llion             #+#    #+#             */
/*   Updated: 2022/07/23 14:39:13 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	diff = *s1 - *s2;
	return (diff);
}

char	*ft_sort_tab_of_str(char *tab[], int size)
{
	int		i;
	int		j;
	char	*arg_min;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) >= 0)
			{
				arg_min = tab[j];
				tab[j] = tab[i];
				tab[i] = arg_min;
			}
			j++;
		}
		i++;
	}
	return (*tab);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = argc;
	ft_sort_tab_of_str(argv + 1, argc - 1);
	while (i < argc)
	{	
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		j--;
		i++;
	}	
}
