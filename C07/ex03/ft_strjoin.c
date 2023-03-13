/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:17:09 by llion             #+#    #+#             */
/*   Updated: 2022/07/27 17:08:30 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcat_size(int size, char **strs)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			counter++;
		}
		i++;
	}
	return (counter);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;	
	int		strcat_size;
	int		i;

	i = 0;
	strcat_size = (ft_strcat_size(size, strs) + (ft_strlen(sep) * (size - 1)));
	if (size == 0)
	{
		str_cat = malloc(sizeof(char));
		str_cat[0] = '\0';
		return (str_cat);
	}
	str_cat = malloc((strcat_size + 1) * sizeof(char));
	if (str_cat == 0)
		return (0);
	str_cat[0] = 0;
	while (i < size)
	{
		ft_strcat(str_cat, strs[i]);
		if (!(i == size - 1))
			ft_strcat(str_cat, sep);
		i++;
	}
	return (str_cat);
}
