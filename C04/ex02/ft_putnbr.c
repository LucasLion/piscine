/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:12:49 by llion             #+#    #+#             */
/*   Updated: 2022/07/25 17:48:22 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		write(1, "-", 1);
		number = nb * -1;
	}
	else
	{
		number = nb;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number = number % 10;
	}
	ft_putchar(number + '0');
}
