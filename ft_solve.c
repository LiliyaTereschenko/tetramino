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

static char *ft_drop_n(char *s, int i)
{
    char *tmp1;
    char *tmp2;
    char *tmp3;
    char *tmp4;
    char *buf;

    tmp1 = ft_strsub(s, i, 4);
    tmp2 = ft_strsub(s, i + 5, 4);
    tmp3 = ft_strsub(s, i + 10, 4);
    tmp4 = ft_strsub(s, i + 15, 4);
    buf = ft_strjoin(tmp1, tmp2);
    tmp1 = buf;
    buf = ft_strjoin(buf, tmp3);
    free(tmp1);
    tmp1 = buf;
    buf = ft_strjoin(buf, tmp4);
    free(tmp1);
    free(tmp2);
    free(tmp3);
    free(tmp4);
    return (buf);
}

/*static void printFromHead(t_list *list) 
{
	if (list)
	{
		printf("%d ", *((int *)list->content));
		printFromHead(list->next);
	}
}*/

static int ft_pos_count(char *buf, int map_size)
{
    int start;
    int end;

    start = ft_ind_start(buf);
    end = ft_ind_end(buf);
    //printf ("start: %d, end: %d, map_size: %d\n", start, end, map_size);
    return ((map_size - end % 4 + start % 4) *\
    (map_size - end / 4 + start / 4));
}

static void ft_create_pose(t_list **matrix, char *buf, int map_size, char letter)
{
    t_list *l;
    t_list *l_matrix;
    int i;
    int pos_count;
    int start;
    int end;
    int tmp;

    //printf ("START: %d, END: %d\n", start, end);
    end = ft_ind_end(buf) - ft_ind_start(buf);
    start = 0;
    i = 0;
    pos_count = ft_pos_count(buf, map_size);
    while (i < pos_count)
    {
        l = ft_create_list(buf, map_size, start);
        //printf("%c %d >>>>>>> ", (char)letter, i);
        //printFromHead(l);
        //printf("\n");
        l_matrix = ft_lstnew(l, sizeof(t_list));
        ft_lst_push_back(matrix, l_matrix);
        l_matrix->content_size = (size_t)letter;
        i++;
        if (end % map_size == map_size - 1)
        {
            tmp = start;
            start += end % map_size - start % map_size + 1;
            end += end % map_size - tmp % map_size + 1;
        }
        else
        {
            start++;
            end++;
        }
    }
}

static void ft_create_one_map(t_list **matrix, char *buf, char *s, char letter)
{
    int map_size;

    map_size = ft_map_size(s);
    ft_create_pose(matrix, buf, map_size, letter);
}

void    ft_solve(char *s)
{
    t_list *matrix;
    int i;
    int map_count;
    char letter;
    char *buf;
    int j;
    t_list *res;

    letter = 'A';
    i = 0;
    j = 0;
    matrix = NULL;
    map_count = ft_map_count(s);
    while (i < map_count)
    {
        buf = ft_drop_n(s, j);
        //printf("%s\n", buf);
        j += 21;
        ft_create_one_map(&matrix, buf, s, letter);
        free(buf);
        letter++;
        i++;
    }
    //printf ("\n=======================\n\n");
    res = NULL;
    ft_algorithm(matrix, &res);
}