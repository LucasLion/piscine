/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:46:35 by llion             #+#    #+#             */
/*   Updated: 2022/07/15 08:15:14 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_putchar(first / 10 + 48);
			ft_putchar(first % 10 + 48);
			ft_putchar(' ');
			ft_putchar(second / 10 + 48);
			ft_putchar(second % 10 + 48);
			if (first < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second++;
		}
		first++;
	}
}
