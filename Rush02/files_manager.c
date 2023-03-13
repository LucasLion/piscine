/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:43:48 by llion             #+#    #+#             */
/*   Updated: 2022/07/31 13:33:57 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	open_file(char *file_path)
{
	int	file;

	file = open(file_path, O_RDONLY);
	if (file == -1)
		write(2, "Dict Error\n", 11);
	return (file);
}

void	len_file(int file, int *len, int *nb_lines)
{
	char	buffer[2];

	buffer[0] = '\n';
	*len = 0;
	*nb_lines = 0;
	while (read(file, &buffer[1], 1))
	{
		if (buffer[1] == '\n' && buffer[0] != '\n')
			*nb_lines += 1;
		*len += 1;
		buffer[0] = buffer[1];
	}
}
