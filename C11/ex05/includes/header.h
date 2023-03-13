/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:28:40 by llion             #+#    #+#             */
/*   Updated: 2022/11/01 10:39:18 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int		operators(char op);
int		check_errors(int argc, char **argv);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif
