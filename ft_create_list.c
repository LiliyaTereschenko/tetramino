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

/*static void printFromHead(t_list *list) 
{
	if (list)
	{
		printf("%d ", *((int *)list->content));
		printFromHead(list->next);
	}
}*/

t_list     *ft_create_list(char *buf, int map_size, int start)
{
    t_list  *beg;
    t_list *l;
    int     i;
    int n;

    i = 0;
    beg = NULL;
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
        //printf(">%s\n", buf);
        *((int *)l->content_size) = i;
        if (buf[i] == '#')
        {
            //printf ("i = %d, start = %d\n", i, start);
            l = ft_lst_at(beg, (unsigned int)(i - ft_ind_start(buf) + start));
            *((int *)l->content) = 1;
        }
        i++;
    }
    //printf("ORIGIN LIST\n");
    //printFromHead(beg);
    //printf("\n===========================================\n");
    return (beg);
}