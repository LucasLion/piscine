/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:46:10 by llion             #+#    #+#             */
/*   Updated: 2022/07/25 15:50:55 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)

{
	int	f;
	int	i;

	i = 1;
	f = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		f *= i;
		i++;
	}
	return (f);
}
