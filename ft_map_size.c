/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:17:06 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/07 16:17:07 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_map_size(char *s)
{
    int    i;
    int map_count;
    /*int width;
    int height;

    width = ft_ind_end(buf) % 4 - ft_ind_start(buf) % 4 + 1;
    height = ft_ind_end(buf) / 4 - ft_ind_start(buf) / 4 + 1;*/

    i = 1;
    map_count = ft_map_count(s);
    while (i * i < map_count * 4)
        i++;
    return (i);
}