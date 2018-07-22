/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:58:49 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/22 15:52:16 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

char							**read_file(int fd);
int								ft_count_words(char *str);
int								**split_char(char **str, int fd);

typedef struct					s_key
{
	void						*mlx;
	void						*win;
}								t_key;

typedef struct					s_points
{
	double						x;
	double						y;
	double						z;
	int							c;
	struct s_points				*next;
	struct s_points				*right;
	struct s_points				*up;
}								t_points;

typedef struct					s_more
{
	int							x;
	int							y;
	int							z;
	int							x1;
	int							y1;
	int							x2;
	int							y2;
	int							x3;
	int							y3;
}								t_more;

typedef struct					s_coord
{
	int							x;
	int							y;
	int							z;
	int							angle;
	int							w;
}								t_coord;

typedef struct					s_axis
{
	int							i;
	int							n;
	int							j;
	int							a;
	int							x;
	int							y;
}								t_axis;

typedef struct					s_env
{
	t_key						mlx;
	t_points					*points;
}								t_env;

typedef struct					s_draw
{
	double						dx;
	double						dy;
	double						x;
	double						y;
	double						steps;
	double						xinc;
	double						yinc;
}								t_draw;

typedef struct					s_coordinates
{
	int							x0;
	int							x1;
	int							y0;
	int							y1;
	int							color;
}								t_coordinates;

typedef struct					s_fds
{
	int							fd;
	int							fd1;
	int							fd2;
}								t_fds;

int								print_map(t_env *env);
int								key_set(int keycode, t_points *points);
void							drawline(t_coordinates c, int x1,
								int y1, t_key mlx);
void							draw_straight_line(int x0, int y0,
								int x1, int y1, t_key mlx, int color);
t_points						*coordinates(int **tab, int fd);
void							draw(t_coordinates c, int x1,
								int y1, t_key mlx);
void							drawl(int x0, int y0, int x1,
								int y1, t_key mlx, int color);
double							ft_abs(double n);

#endif
