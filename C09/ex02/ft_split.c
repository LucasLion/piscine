/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:37:17 by llion             #+#    #+#             */
/*   Updated: 2022/11/08 11:55:36 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	tab_len(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if (i == 0)
		{
			while (check_charset(str[i], charset) && str[i])
				i++;
		}
		if (!check_charset(str[i], charset))
			word_count++;
		while (!check_charset(str[i], charset))
			i++;
		if (!(str[i] == '\0'))
			i++;
	}
	return (word_count);
}

int	word_len(char *str, char *charset, int *i)
{
	int	word_count;

	word_count = 0;
	while (!(check_charset(str[*i], charset)))
	{
		word_count++;
		(*i)++;
	}
	return (word_count);
}

char	*catch_word(char *str, char *charset, int *i)
{
	int		word_length;
	char	*word;
	int		j;

	word = 0;
	if (check_charset(str[*i], charset))
		while (check_charset(str[*i], charset))
			(*i)++;
	if ((str[*i]) != '\0' && (!(check_charset(str[*i], charset))))
	{
		j = 0;
		word_length = word_len(str, charset, i);
		word = malloc((word_length + 1) * sizeof(char));
		while (j < word_length)
		{
			word[j] = str[*i - word_length];
			(*i)++;
			j++;
		}
		*i -= word_length;
		word[j] = '\0';
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = tab_len(str, charset);
	tab = malloc((len + 1) * sizeof(char *));
	if (tab == 0)
		return (0);
	tab[j] = 0;
	while (j < len)
	{
		tab[j] = catch_word(str, charset, &i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
