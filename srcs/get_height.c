/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 06:54:00 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/29 11:08:34 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points		*get_height(char **str, t_rows d, t_points *lst)
{
	t_axis	c;

	c.y = 0;
	int j = 0;
	while (d.rows > 0)
	{
		c.x = 0;
	//	printf("here!\n");
		c.columns = d.columns;
		c.array = ft_strsplit(str[c.y], ' ');
		while (c.columns > 0)
		{
			//printf("%i, got in\n", j);
			lst->z = ft_atoi(c.array[c.x]);
			if (!(d.rows == 1 && c.columns == 1))
				lst->next = malloc(sizeof(t_points));
			if (lst->next == NULL)
				return (NULL);
			lst = lst->next;
			lst->next = NULL;
			c.x++;
			c.columns--;
			j++;
		}
		//free_2d_array((void**)c.array);
		d.rows--;
		c.y++;
	}
	return (lst);
}
