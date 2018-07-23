/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 08:04:39 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/23 11:01:08 by smarwise         ###   ########.fr       */
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

int			**real_split_char(t_axis counter, t_do c, int fd, char **str)
{
	while (get_next_line(fd, &c.line) == 1)
	{
		counter.j++;
		ft_strdel(&c.line);
	}
	c.tab = (int **)malloc(sizeof(int *) * (counter.j + 1));
	while (counter.n < counter.j)
	{
		counter.a = 0;
		c.str1 = ft_strsplit(str[counter.i], ' ');
		counter.x = ft_count_words(str[counter.i]);
		c.tab[counter.n] = (int *)malloc(sizeof(int) * (counter.x + 1));
		while (counter.x > 0)
		{
			c.tab[counter.n][counter.a] = ft_atoi(c.str1[counter.a]);
			counter.a++;
			counter.x--;
		}
		c.tab[counter.n][counter.a] = '\0';
		counter.i++;
		counter.n++;
		free_2d_array((void**)c.str1);
	}
	c.tab[counter.n] = NULL;
	return (c.tab);
}

int			**split_char(char **str, int fd)
{
	t_axis	counter;
	t_do	c;

	counter.i = 0;
	counter.n = 0;
	counter.j = 0;
	counter.x = 0;
	counter.a = 0;
	c.line = NULL;
	return (real_split_char(counter, c, fd, str));
}
