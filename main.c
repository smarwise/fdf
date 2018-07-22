/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/22 15:07:12 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

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
	}
	return (0);
}
