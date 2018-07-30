/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:43:03 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/28 16:24:27 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotx(t_points *points, double angle)
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

void		rot_y(t_points *points, double angle)
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

void		rot_z(t_points *points, double angle)
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

void		rotateforme(t_points *points, int keycode)
{
	if (keycode == 88)
		rot_z(points, 10 * M_PI / 180);
	if (keycode == 86)
		rot_z(points, -10 * M_PI / 180);
	if (keycode == 2)
		rot_y(points, 10 * M_PI / 180);
	if (keycode == 40)
		rot_y(points, -10 * M_PI / 180);
	if (keycode == 11)
		rotx(points, 10 * M_PI / 180);
	if (keycode == 16)
		rotx(points, -10 * M_PI / 180);
}
