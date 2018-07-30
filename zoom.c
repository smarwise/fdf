/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:20:15 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/28 14:06:10 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoomout(t_points *points)
{
	while (points)
	{
		points->scale += 1;
		points = points->next;
	}
}

void		zoomin(t_points *points)
{
	while (points)
	{
		points->scale -= 1;
		points = points->next;
	}
}

void		zoomforme(t_points *points, int keycode)
{
	if (keycode == 69)
		zoomout(points);
	if (keycode == 78)
		zoomin(points);
}
