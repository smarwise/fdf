/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:15:51 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/30 08:32:12 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char        *ccreate_file_content(char *curr, char *to_add, size_t rsize)
{
    char    *new;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    new = (char*)malloc(sizeof(char) * ft_strlen(curr) + rsize + 1);
    while (curr[i])
    {
        new[i] = curr[i];
        i++;
    }
    while (j < rsize)
    {
        new[i] = to_add[j];
        j++;
        i++;
    }
    new[i] ='\0';
    return (new);
}

t_rows		thetest(int fd)
{
    size_t  rsize;
	t_rows	d;
    char    *new;
    char    **ret;
    char    buffer[1000];

	d.rows = 0;
    new = (char*)malloc(sizeof(char));
    while ((rsize = read(fd, buffer, 1000)))
    {
        new = ccreate_file_content(new, buffer, rsize);
    }
    ret = ft_strsplit(new, '\n');
	d.columns = ft_count_words(ret[0]);
	while (ret[d.rows])
		d.rows++;
    free(new);
	free_2d_array((void**)ret);
    return (d);
}

t_rows		dimensions(int fd)
{
	return (thetest(fd));
}
