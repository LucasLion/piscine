/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:44:18 by llion             #+#    #+#             */
/*   Updated: 2022/07/20 18:15:45 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*convert_de_to_hex(int decimal)
{
	int			quotient;
	int			temp;
	int			i;
	int			j;
	static char	hexadecimal_number[10];

	i = 0;
	j = 0;
	quotient = decimal;
	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
		{
			temp = temp + 48;
		}
		else
		{
			temp = temp + 87;
		}
		hexadecimal_number[i] = temp;
		quotient = quotient / 16;
		i++;
	}
	return (hexadecimal_number);
}	

void	rev_and_put_hexa(char *rev_hex)
{
	int	i;

	i = ft_strlen(rev_hex);
	while (i >= 0)
	{
		ft_putchar(rev_hex[i]);
		i--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;	
	char	*hex;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			hex = convert_de_to_hex(str[i]);
			ft_putchar('\\');
			if (str[i] < 16)
			{
				ft_putchar('0');
			}
			rev_and_put_hexa(hex);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
