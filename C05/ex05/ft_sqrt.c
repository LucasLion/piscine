/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:53:37 by llion             #+#    #+#             */
/*   Updated: 2022/07/24 11:13:53 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ftt_sqrt(int nb, int factor)
{
	if (factor * factor < nb)
	{
		if (factor >= 46341)
			return (0);
		return (ftt_sqrt(nb, factor + 1));
	}
	if (factor * factor == nb)
	{
		return (factor);
	}
	else
		return (0);
}

int	ft_sqrt(int nb)
{
	int	factor;

	factor = 1;
	return (ftt_sqrt(nb, factor));
}
