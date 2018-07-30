/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:13:43 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/30 08:03:58 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_points			*get_link(int link, t_points *head)
{
	while (--link)
		head = head->next;
	if (head)
		return (head);
	else
		return (NULL);
}

t_points			*rot_x(t_points *points, double angle, t_points *head)
{
	double			y;

	points = head;
	while (points)
	{
		y = cos(angle) * points->y - sin(angle) * points->z;
		points->z = cos(angle) * points->z + sin(angle) * points->y;
		points->y = y;
		points = points->next;
	}
	points = head;
	return (head);
}

t_points			*allocate(t_axis cnt,
		t_points *lst, t_points *head, char **argv)
{
	while (cnt.y < cnt.rows)
	{
		cnt.x = 0;
		while (cnt.x < cnt.columns)
		{
			lst->x = cnt.x - cnt.columns / 2;
			lst->y = cnt.y - cnt.rows / 2;
			cnt.x++;
			if (cnt.x < cnt.columns)
				lst->right = lst->next;
			else
				lst->right = NULL;
			if (cnt.y)
				lst->up = get_link((cnt.y - 1) * cnt.columns + cnt.x, head);
			else
				lst->up = NULL;
			if (!argv[2] || !argv[3])
				lst->c = lst->z > 0 ? 0xeff628 : 0x28acf6;
			else
				lst->c = lst->z > 0 ? ft_atoi(argv[3]) : ft_atoi(argv[2]);
			lst = lst->next;
		}
		cnt.y++;
	}
	ft_putendl("\nleaving allocate()");
	return (rot_x(lst, 10 * M_PI / 180, head));
}

t_points			*coordinates(char **str, t_rows d, char **argv)
{
	t_axis			cnt;
	t_points		*lst;
	t_points		*head;

	cnt.y = 0;
	cnt.rows = d.rows;
	cnt.columns = d.columns;
	head = (t_points *)ft_memalloc(sizeof(t_points));
	if (head == NULL)
		return (NULL);
	lst = head;
	lst = get_height(str, d, lst);
	free_2d_array((void**)str);
	lst = head;
	while (lst)
	{
		lst->scale = 25;
		lst->shift = 400;
		lst = lst->next;
	}
	lst = head;
	return (allocate(cnt, lst, head, argv));
}
