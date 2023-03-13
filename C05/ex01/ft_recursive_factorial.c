/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:46:17 by llion             #+#    #+#             */
/*   Updated: 2022/07/25 15:50:45 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	fact = 0;
	if ((nb == 1) || (nb == 0))
		return (1);
	if (nb > 1)
		fact = nb * ft_recursive_factorial(nb - 1);
	return (fact);
}
