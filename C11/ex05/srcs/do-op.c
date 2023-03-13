/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:19:16 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 11:51:58 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_errors(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int	operators(char sign)
{
	if (sign == '+')
		return (0);
	if (sign == '-')
		return (1);
	if (sign == '*')
		return (2);
	if (sign == '/')
		return (3);
	if (sign == '%')
		return (4);
	return (5);
}

int	main(int argc, char **argv)
{
	int	(*tab[5])(int, int);
	int	operator;
	int	result;

	if (check_errors(argc, argv))
		return (1);
	tab[0] = &add;
	tab[1] = &sub;
	tab[2] = &mul;
	tab[3] = &div;
	tab[4] = &mod;
	operator = operators(argv[2][0]);
	if (operator == 5)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	result = tab[operator](ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
