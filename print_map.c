/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:28:00 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/22 14:59:09 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					print_map(t_env *env)
{
	t_points		*points;
	t_coordinates	c;

	points = env->points;
	while (points)
	{
		c.color = points->c;
		if (points->right)
		{
			c.x0 = points->x * 25 + 400;
			c.y0 = points->y * 25 + 400;
			draw(c, points->right->x * 25 + 400,
					points->right->y * 25 + 400, env->mlx);
		}
		if (points->up)
		{
			c.x0 = points->x * 25 + 400;
			c.y0 = points->y * 25 + 400;
			draw(c, points->up->x * 25 + 400,
					points->up->y * 25 + 400, env->mlx);
		}
		points = points->next;
	}
	mlx_clear_window(env->mlx.mlx, env->mlx.win);
	return (0);
}
