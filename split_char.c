/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:04:39 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/22 16:05:09 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '\0')
		return (count);
	while (str[i])
	{
		if (str[i] == '\0')
			return (count);
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
		count++;
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	return (count);
}

int			**real_split_char(t_axis counter, char *line, int fd, char **str)
{
	int		l;
	char	**str1;
	int		**tab;

	while (get_next_line(fd, &line) == 1)
		counter.j++;
	tab = (int **)malloc(sizeof(int *) * (counter.j + 1));
	while (counter.n < counter.j)
	{
		counter.a = 0;
		str1 = ft_strsplit(str[counter.i], ' ');
		l = ft_count_words(str[counter.i]);
		tab[counter.n] = (int *)malloc(sizeof(int) * (l + 1));
		while (l > 0)
		{
			tab[counter.n][counter.a] = ft_atoi(str1[counter.a]);
			counter.a++;
			l--;
		}
		tab[counter.n][counter.a] = '\0';
		counter.i++;
		counter.n++;
	}
	tab[counter.n] = NULL;
	return (tab);
}

int			**split_char(char **str, int fd)
{
	t_axis	counter;
	char	*line;

	counter.i = 0;
	counter.n = 0;
	counter.j = 0;
	counter.a = 0;
	line = NULL;
	return (real_split_char(counter, line, fd, str));
}
