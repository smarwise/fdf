/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:17:37 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/12 09:21:27 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**read_file(int fd)
{
	char	*line;
	char	**c_array;
	int		n;

	n = 0;
	c_array = (char **)malloc(sizeof(char *) * (20));
	while (get_next_line(fd, &line) == 1)
	{
		c_array[n] = ft_strdup(line);
		n++;
	}
	c_array[n] = NULL;
	return (c_array);
}
