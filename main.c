/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/23 10:42:49 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

void		tidy_up(t_fds f, t_points *head)
{
	close(f.fd);
	close(f.fd1);
	close(f.fd2);
	free_t_point(head);
}

int			main(int argc, char **argv)
{
	t_env	env;
	char	**array;
	int		**tab;
	t_fds	f;

	if (argc > 1)
	{
		env.mlx.mlx = mlx_init();
		env.mlx.win = mlx_new_window(env.mlx.mlx, 800, 800, "fdf");
		f.fd = open(argv[1], O_RDONLY);
		array = read_file(f.fd);
		f.fd1 = open(argv[1], O_RDONLY);
		tab = split_char(array, f.fd1);
		f.fd2 = open(argv[1], O_RDONLY);
		env.points = coordinates(tab, f.fd2);
		print_map(&env);
		mlx_key_hook(env.mlx.win, key_set, env.points);
		mlx_loop_hook(env.mlx.mlx, print_map, &env);
		mlx_loop(env.mlx.mlx);
		tidy_up(f, env.points);
	}
	return (0);
}
