/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:10:49 by llion             #+#    #+#             */
/*   Updated: 2022/07/24 18:44:33 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	test_solution(void)
{
	int	tab[4][4];
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	a = '1';
	b = '1';
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a == '5')
				a = '1';
			tab[i][j] = a;
			ft_putchar(tab[i][j]);
			j++;
			a++;
			write(1, " ", 1);
		}
		a = b + 1;
		b++;
		write(1, "\n", 1);
		i++;
	}
}

int	argument_lengh(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argv[1][i])
	{
		if ((argv[1][i] != ' '))
		{
			write(1, "Error\n", 12);
			return (1);
		}
		i += 2;
	}
	if (argc != 2)
	{
		write(1, "Error\n", 10);
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		write(1, "Error\n", 10);
		return (1);
	}
	return (0);
}

int	argument_testing(int argc, char *argv[])
{
	int	i;
	int	dumb;

	dumb = argc;
	i = 0;
	while (argv[1][i])
	{	
		if ((argv[1][i] < '1' || argv[1][i] > '4'))
		{
			write(1, "Error\n", 10);
			return (1);
		}
		if (argv[1][i + 1] != '\0')
			i += 2;
		else
			i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{	
	int	error;

	error = argument_testing(argc, argv);
	if (error)
		return (0);
	test_solution();
}





