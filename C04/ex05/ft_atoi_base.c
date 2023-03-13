/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:56:13 by llion             #+#    #+#             */
/*   Updated: 2022/07/27 17:51:52 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (sign % 2 == 0)
		return (1);
	else
		return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

int	convert_str_to_decimal(char *str, char *base)
{
	int	i;
	int	j;
	int	base_len;
	int	dec_num;

	dec_num = 0;
	base_len = ft_strlen(base);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < base_len)
		{
			if (str[i] == base[j])
			{
				dec_num = (dec_num * base_len) + j;
				break ;
			}
			j++;
		}
		if (str[i] != base[j])
			break ;
		i++;
	}
	return (dec_num);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	sign;
	unsigned int	number;
	unsigned int	base_len;

	i = 0;
	number = 0;
	base_len = ft_strlen(base);
	if (!(check_base(base)))
		return (0);
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		sign = get_sign(&str[i]);
	while ((str[i] == '+') || (str[i] == '-'))
		i++;
	number = convert_str_to_decimal(&str[i], base);
	if (sign)
		return (number);
	else
		return (-number);
}
