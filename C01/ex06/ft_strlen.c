/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:13:49 by llion             #+#    #+#             */
/*   Updated: 2022/08/04 17:40:46 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;
	int	endstr;

	endstr = '\0';
	count = 0;
	while (*str != endstr)
	{
		str++;
		count++;
	}
	return (count);
}

int main(void)
{
	char *str = "coucou";
	int i = ft_strlen(str);
	printf("%d\n", i);
}
