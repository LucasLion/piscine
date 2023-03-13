/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:00:57 by llion             #+#    #+#             */
/*   Updated: 2022/07/19 13:40:13 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// retourne la valeur copiée (dest + size)
// la fonction ajoute  src a la fin  de dst
// elle ajoute "au plus" size - 1 caracteres et ajoute \0 a la fin
// sauf si size == 0 ou si dst > dest est plus grand que size 
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
}
