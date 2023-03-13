/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:49:22 by llion             #+#    #+#             */
/*   Updated: 2022/07/20 08:44:49 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


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

// cet exercice est potentiellement corrigé --- à voir
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
