/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:52:03 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/07 15:52:08 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list     *ft_create_list(char *buf, int map_size)
{
    t_list  *beg;
    t_list *l;
    int start;
    int     i;
    int n;

    i = 0;
    beg = NULL;
    start = ft_ind_start(buf);
    n = 0;
    while (i < map_size * map_size)
    {
        l = ft_lstnew(&n, sizeof(int));
        ft_lst_push_back(&beg, l);
        i++;
    }
    i = 0;
    //printf("letter: %c\n", (char)l->content_size);
    //printFromHead(beg);
    //printf("start: %d\n", start);
    while (buf[i])
    {
        if (buf[i] == '#')
        {
            //printf ("i = %d\n", i);
            l = ft_lst_at(beg, (unsigned int)(i - start + (map_size - 5) * (i / 5 - start / 5)));
            *((int *)l->content) = 1;
        }
        i++;
    }
    //printFromHead(beg);
    //printf("\n===========================================\n");
    return (beg);
}