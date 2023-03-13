/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:43:11 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/07/31 19:54:28 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	free_3d_tab(char ***tab_to_free, int len);
char	***parsefile(char *file, int *len);
int		len_str(char *str);
char	*find(char fo_find, char ***dict, int dozen, int size);
char	*find_separator(int nb_zeros, char ***dict, int nb_lines);
void	display(char *number, char ***dict, int nb_lines);

void ft_pustr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
		
}

int	len_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*find(char to_find, char ***dict, int dozen, int size)
{
	int	i;

	i = 0;
	if (to_find == '0' && size != 1)
		return ("");
	if (!dozen)
		while (!(to_find == dict[i][0][0] && dict[i][0][1] == '\0'))
		{
			i++;
		}
	else
		while (!(to_find == dict[i][0][0] && dict[i][0][1] == '0'
				&& dict[i][0][2] == '\0'))
			i++;
	return (dict[i][1]);
}

char	*dozen(char d, char u, char ***dict)
{
	int		i;

	i = 0;
	while (!(d == dict[i][0][0] && u == dict[i][0][1] && '\0' == dict[i][0][2]))
		i++;
	return (dict[i][1]);
}

char	*find_separator(int nb_zeros, char ***dict, int nb_lines)
{
	int	i;
	int	j;
	int	count;

	if (nb_zeros == 0)
		return ("");
	i = 0;
	while (i < nb_lines)
	{
		if (len_str(dict[i][0]) - 1 == nb_zeros)
			if (dict[i][0][0] == '1')
			{
				j = 0;
				count = 0;
				while (dict[i][0][++j] != '\0')
					if (dict[i][0][j] == '0')
						count++;
				if (count == nb_zeros)
					return (dict[i][1]);
			}
		i++;
	}
	return (NULL);
}

void espace(int i, char *number)
{
	if (number[i] != '0' && i != 0)
		ft_pustr(" ");
}
int verif(char *number, char ***dict, int nb_lines)
{
	int	i;
	int	index;

	i = -1;
	if (len_str(number) % 3 == 0)
		index = 0;
	else if (len_str(number) % 3 == 2)
		index = 1;
	else
		index = 2;
	return (index);
}

void	display_ifs(char *number, char ***dict, int *index, int *i, int nb_lines)
{
	if (*index % 3 == 0) 
	{
		ft_pustr( find(number[*i], dict, 0,len_str(number)));
		ft_pustr(" ");
		ft_pustr( find_separator(2, dict, nb_lines));
	}
	if(*index % 3 == 1)
	{
		if (number[*i] != '1')
			ft_pustr( find(number[*i], dict, 1,len_str(number)));
		else
			ft_pustr( dozen(number[*i], number[*i + 1], dict));
	}
}

void	display(char *number, char ***dict, int nb_lines)
{
	int	i;
	int index;

	index = verif(number, dict, nb_lines);
	i = -1;
	while (++i < len_str(number))
	{
		espace(i, number);
		if (number[i] != '0') 
			display_ifs(number, dict, &index, &i, nb_lines);
		if (index % 3 == 2)
			if (i != '0' && number[i - 1] != '1')
				ft_pustr( find(number[i], dict, 0,len_str(number)));
		if (index % 3 == 2 
				&& (number[i] != '0'
				 || (i > 0 && number[i - 1] != '0')
				 || (i > 1 && number[i - 2] != '0')))
			{
				if (i < len_str(number) - 1)
					ft_pustr(" ");
					ft_pustr(find_separator(len_str(number) - i - 1, dict, nb_lines));		
			}
		index++;
	}	
}
