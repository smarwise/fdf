/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:10:37 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/22 15:09:25 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_points *points, double angle)
{
	double	y;

	while (points)
	{
		y = cos(angle) * points->y - sin(angle) * points->z;
		points->z = cos(angle) * points->z + sin(angle) * points->y;
		points->y = y;
		points = points->next;
	}
}

void	rot_y(t_points *points, double angle)
{
	double	temp;

	while (points)
	{
		temp = cos(angle) * points->x - sin(angle) * points->z;
		points->z = cos(angle) * points->z + sin(angle) * points->x;
		points->x = temp;
		points = points->next;
	}
}

void	rot_z(t_points *points, double angle)
{
	double	y;

	while (points)
	{
		y = cos(angle) * points->x - sin(angle) * points->y;
		points->y = cos(angle) * points->y + sin(angle) * points->x;
		points->x = y;
		points = points->next;
	}
}

int		key_set(int keycode, t_points *points)
{
	int		i;

	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		rot_z(points, 10 * M_PI / 180);
	if (keycode == 126)
		rot_z(points, -10 * M_PI / 180);
	if (keycode == 123)
		rot_y(points, 10 * M_PI / 180);
	if (keycode == 13)
		rot_y(points, -10 * M_PI / 180);
	if (keycode == 5)
		rot_x(points, 10 * M_PI / 180);
	if (keycode == 125)
		rot_x(points, -10 * M_PI / 180);
	return (0);
}
