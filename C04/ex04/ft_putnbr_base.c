/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:04:35 by llion             #+#    #+#             */
/*   Updated: 2022/07/27 17:51:41 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	endstr;

	endstr = '\0';
	while (*str != endstr)
	{
		write(1, str, 1);
		str++;
	}	
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_nbr;
	unsigned int	number_to_display;
	unsigned int	number;

	if (check_base(base))
	{
		base_nbr = ft_strlen(base);
		number = nbr;
		if (nbr < 0)
		{
			ft_putchar('-');
			number = -nbr;
		}
		if (number > base_nbr)
		{
			ft_putnbr_base(number / base_nbr, base);
			number_to_display = base[number % base_nbr];
			number = number % 10;
		}
		else
			number_to_display = base[number];
		ft_putchar(number_to_display);
	}
}
