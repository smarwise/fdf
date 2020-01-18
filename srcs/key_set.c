/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:10:37 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/28 13:51:29 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_set(int keycode, t_points *points)
{
	int		i;

	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 88 || keycode == 86 || keycode == 11
			|| keycode == 40 || keycode == 16 || keycode == 2)
		rotateforme(points, keycode);
	if (keycode == 69 || keycode == 78)
		zoomforme(points, keycode);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		shiftforme(points, keycode);
	return (0);
}
