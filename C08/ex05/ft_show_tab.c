/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:13:18 by llion             #+#    #+#             */
/*   Updated: 2022/08/01 15:43:45 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		write(1, "-", 1);
		number = -nb;
	}
	else
		number = nb;
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number = number % 10;
	}
	ft_putchar(number + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (par[i].str != 0)
	{
		len++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
