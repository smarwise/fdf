/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 09:25:42 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/29 12:34:31 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					print_map(t_env *env)
{
	t_points		*points;
	t_coordinates	c;

	points = env->points;
	while (points)
	{
		c.color = points->c;
		if (points->right != NULL && points)
		{
			c.x0 = points->x * points->scale + points->shift;
			c.y0 = points->y * points->scale + points->shift;
			draw(c, points->right->x * points->scale + points->shift,
					points->right->y * points->scale + points->shift, env->mlx);
		}
		if (points->up != NULL && points)
		{
			c.x0 = points->x * points->scale + points->shift;
			c.y0 = points->y * points->scale + points->shift;
			draw(c, points->up->x * points->scale + points->shift,
					points->up->y * points->scale + points->shift, env->mlx);
		}
		points = points->next;
	}
	mlx_clear_window(env->mlx.mlx, env->mlx.win);
	return (0);
}
