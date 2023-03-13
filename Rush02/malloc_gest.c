/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:41:11 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/07/30 23:57:57 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_3d_tab(char ***tab_to_free, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab_to_free[i][0]);
		free(tab_to_free[i][1]);
		free(tab_to_free[i]);
		i++;
	}
	free(tab_to_free);
}
