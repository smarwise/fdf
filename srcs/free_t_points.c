/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:20 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/23 10:49:42 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			free_t_point(t_points *head)
{
	t_points	*trav;

	trav = head;
	while (trav)
	{
		trav = trav->next;
		free(head);
		head = trav;
	}
}
