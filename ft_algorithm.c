/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:21:37 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 18:21:39 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void printFromHead(t_list *list) 
{
	if (list)
	{
		printf("%d ", *((int *)list->content));
		printFromHead(list->next);
	}
}

static t_list *ft_lst_copy(t_list *matrix)
{
    t_list *m_copy;
    t_list *small;
    t_list *l;
    t_list *p;

    m_copy = NULL;
    l = matrix;
    while (l)
    {
        small = NULL;
        p = l->content;
        while (p)
        {
            ft_lst_push_back(&small, p);
            p = p->next;
        }
        printFromHead(small);
        printf("\n");
        ft_lst_push_back(&m_copy, small);
        l = l->next;
    }
    return (m_copy);
}

int    ft_algorithm(t_list *matrix, t_list **res)
{
    t_list *m_copy;

    m_copy = ft_lst_copy(matrix);
    res = NULL;
    return (1);
}