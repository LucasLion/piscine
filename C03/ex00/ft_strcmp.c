/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:30:06 by llion             #+#    #+#             */
/*   Updated: 2022/07/24 14:08:51 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
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

int	ft_strcmp(char *s1, char *s2)
{

	int	diff;

	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	diff = *s1 - *s2;
	return (diff);
}

int main(void)
{
	unsigned int	a;
	char s1[] = "ola";
	char s2[] = "olo";

	a = ft_strcmp(s1, s2);
	ft_putnbr(a);
}
