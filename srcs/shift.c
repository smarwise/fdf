/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:25:43 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/28 14:03:55 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		shiftup(t_points *points)
{
	while (points)
	{
		points->y -= 0.2;
		points = points->next;
	}
}

void		shiftdown(t_points *points)
{
	while (points)
	{
		points->y += 0.2;
		points = points->next;
	}
}

void		shiftleft(t_points *points)
{
	while (points)
	{
		points->x -= 0.2;
		points = points->next;
	}
}

void		shiftright(t_points *points)
{
	while (points)
	{
		points->x += 0.2;
		points = points->next;
	}
}

void		shiftforme(t_points *points, int keycode)
{
	if (keycode == 126)
		shiftup(points);
	if (keycode == 125)
		shiftdown(points);
	if (keycode == 123)
		shiftleft(points);
	if (keycode == 124)
		shiftright(points);
}
