/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:58:49 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/29 10:27:45 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

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
	int							scale;
	int							shift;
	struct s_points				*next;
	struct s_points				*right;
	struct s_points				*up;
}								t_points;

void							free_t_point(t_points *head);

typedef struct					s_axis
{
	int							x;
	int							y;
	int							rows;
	int							columns;
	char						**array;
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
	int							y0;
	int							color;
}								t_coordinates;

typedef struct					s_rows
{
	int							rows;
	int							columns;
}								t_rows;

typedef struct					s_fds
{
	int							fd;
	int							fd1;
}								t_fds;

char							**test(int fd);
int								print_map(t_env *env);
t_points						*get_height(char **str, t_rows d,
		t_points *lst);
char							**read_file(int fd, t_rows d);
int								key_set(int keycode, t_points *points);
t_points						*coordinates(char **str, t_rows d, char **argv);
void							draw(t_coordinates c, int x1,
								int y1, t_key mlx);
t_rows							dimensions(int fd);
double							ft_abs(double n);
void							zoomforme(t_points *points, int keycode);
void							shiftforme(t_points *points, int keycode);
void							rotateforme(t_points *points, int keycode);

#endif
