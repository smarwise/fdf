/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:13:43 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/23 10:33:36 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_points			*get_link(int link, t_points *head)
{
	while (--link)
		head = head->next;
	return (head);
}

void				initialize(int j, int a, int y, int x)
{
	j = 0;
	a = 0;
	y = 0;
	x = 0;
}

t_points			*allocate(t_axis cnt,
		t_points *lst, t_points *head, int **tab)
{
	while (cnt.y < cnt.j)
	{
		cnt.x = 0;
		while (cnt.x < cnt.a)
		{
			lst->x = cnt.x - cnt.a / 2;
			lst->y = cnt.y - cnt.j / 2;
			lst->z = tab[cnt.y][cnt.x];
			cnt.x++;
			if (cnt.y < cnt.j || cnt.x < cnt.a)
				lst->next = (t_points*)ft_memalloc(sizeof(t_points));
			if (cnt.x < cnt.a)
				lst->right = lst->next;
			if (cnt.y)
				lst->up = get_link((cnt.y - 1) * cnt.a + cnt.x, head);
			if (lst->z >= 0 && lst->z <= 10)
				lst->c = lst->z > 0 ? 0xeff628 : 0x28acf6;
			else
				lst->c = lst->z > 0 ? 0x50be62 : 0xf62f28;
			lst = lst->next;
		}
		cnt.y++;
	}
	return (head);
}

t_points			*coordinates(int **tab, int fd)
{
	t_axis			cnt;
	char			*line;
	t_points		*lst;
	t_points		*head;
	char			**arrayline;

	arrayline = NULL;
	cnt.j = 0;
	cnt.a = 0;
	cnt.y = 0;
	cnt.x = 0;
	initialize(cnt.j, cnt.a, cnt.y, cnt.x);
	while (get_next_line(fd, &line) == 1)
	{
		cnt.j++;
		arrayline = arraypush(arrayline, line);
	}
	cnt.a = ft_count_words(arrayline[arraylen(arrayline) - 1]);
	free_2d_array((void**)arrayline);
	head = (t_points *)ft_memalloc(sizeof(t_points));
	lst = head;
	if (head == NULL)
		return (NULL);
	return (allocate(cnt, lst, head, tab));
}
