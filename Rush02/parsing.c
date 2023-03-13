/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:12:09 by llion             #+#    #+#             */
/*   Updated: 2022/07/31 17:39:04 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int		open_file(char *file_path);
void	len_file(int file, int *len, int *nb_lines);
char	***parse(char *str, int nb_lines);
char	***parsefile(char *file, int *nb_lines);
int		skip_spaces(int i, char *str);

char	***parsefile(char *file, int *nb_lines)
{
	char	*str_file;
	int		file1;
	int		len;
	char	***tab;

	file1 = open_file(file);
	len_file(file1, &len, nb_lines);
	printf("%d\n", *nb_lines);
	close(file1);
	file1 = open_file(file);
	str_file = malloc((len + 1) * sizeof(char));
	read(file1, str_file, len);
	str_file[len] = '\0';
	tab = parse(str_file, *nb_lines);
	free(str_file);
	return (tab);
}

char	*ft_strdup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((n) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	skip_spaces(int i, char *str)
{
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (-1);
	i++;
	while (str[i] == ' ')
		i++;
	return (--i);
}

char	*cut_num(char *str, int *i)
{
	int		count;
	char	*number_str;

	count = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ') {
		(*i)++;
	}
	if (str[*i] > '9' || str[*i] < '0')
	{
		if ((str[*i] != '+' && str[*i] != '-') || (str[*i + 1] > '9' || str[*i + 1] < '0'))
			return (NULL);
		else
			(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*i)++;
		count++;
	}
	while ((str[*i] > '9' || str[*i] < '0') && str[*i] != ' ' && str[*i] != ':')
		(*i)++;
	number_str = ft_strdup(&str[*i - count], count);
	return (number_str);
}

char	***parse(char *str, int nb_lines)
{
	char	***tab;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tab = malloc(nb_lines * sizeof(char **));
	while (str[++i] != '\0')
	{
		while (str[i] == '\n')
			i++;
		tab[++j] = malloc(2 * sizeof(char *));
		len = 0;
		tab[j][0] = cut_num(str, &i);
		i = skip_spaces(i, str);
		len = 0;
		while (str[++i] != '\n')
			len++;
		tab[j][1] = ft_strdup(&str[i - len], len);
	}
	return (tab);
}
