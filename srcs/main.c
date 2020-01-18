/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/30 08:04:16 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"
#include <stdlib.h>
#include <stdio.h>

void		tidy_up(t_fds f, t_points *head, char **array, int **tab)
{
	int		n;

	n = 0;
	close(f.fd);
	close(f.fd1);
	free_2d_array((void**)array);
	free_t_point(head);
	while (tab[n])
	{
		free(tab[n]);
		n++;
	}
}

int                     click_set(int b, t_env *v)
{
        (void)b;
        (void)v;
        exit(0);
}

int			main(int argc, char **argv)
{
	t_env	env;
	char	**array;
	t_rows	d;
	t_fds	f;

	if (argc > 1)
	{
		env.mlx.mlx = mlx_init();
		env.mlx.win = mlx_new_window(env.mlx.mlx, 1000, 1000, "fdf");
		f.fd = open(argv[1], O_RDONLY);
		f.fd1 = open(argv[1], O_RDONLY);
		d = dimensions(f.fd);
//		array = read_file(f.fd1, d);
		array = test(f.fd1);
		env.points = coordinates(array, d, argv);
		print_map(&env);
		printf("next milestone\n");
		mlx_key_hook(env.mlx.win, key_set, env.points);
		mlx_hook(env.mlx.win, 17, 0, click_set, env.points);
		mlx_loop_hook(env.mlx.mlx, print_map, &env);
		mlx_loop(env.mlx.mlx);
	//	tidy_up(f, env.points, array, tab);
	}
	return (0);
}
