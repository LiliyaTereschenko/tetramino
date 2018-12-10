/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:56:04 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/07 17:56:05 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list *ft_create_pose(char *buf, int map_size)
{
    t_list *l;

    l = ft_create_list(buf, map_size);
    return (l);
}

static t_list *ft_create_one_map(char *buf, char *s)
{
    int map_size;
    t_list *l;

    map_size = ft_map_size(s);
    l = ft_create_pose(buf, map_size);
    return (l);
}

void printFromHead(t_list *list) 
{
	if (list)
	{
		printf("%d ", *((int *)list->content));
		printFromHead(list->next);
	}
}

void    ft_solve(char *s)
{
    t_list *matrix;
    int i;
    int map_count;
    char letter;
    t_list *l;
    char *buf;
    int j;

    letter = 'A';
    map_count = ft_map_count(s);
    i = 0;
    j = 0;
    matrix = NULL;
    while (i < map_count)
    {
        buf = ft_strsub(s, j, 20);
        j += 21;
        l = ft_lstnew(ft_create_one_map(buf, s), sizeof(t_list));
        free(buf);
        ft_lst_push_back(&matrix, l);
        l->content_size = (size_t)letter;
        letter++;
        i++;
    }
    while (matrix)
    {
        printf("%c > ", (char)(matrix->content_size));
        printFromHead(matrix->content);
        printf("\n");
        matrix = matrix->next;
    }
}