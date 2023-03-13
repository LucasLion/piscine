/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:05:52 by llion             #+#    #+#             */
/*   Updated: 2022/07/29 13:44:46 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

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

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	sign;
	unsigned int	number;

	i = 0;
	number = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		sign = get_sign(&str[i]);
	while ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (sign)
		return (number);
	else
		return (-number);
}
