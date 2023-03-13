/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:03:32 by llion             #+#    #+#             */
/*   Updated: 2022/07/28 10:55:56 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	len(char *str)
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

char	comp_str(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] != str1[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len_to_find;

	len_to_find = len(to_find);
	if (len_to_find == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			if (comp_str(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
