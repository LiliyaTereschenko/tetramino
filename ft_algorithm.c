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

/*static t_list *ft_lst_copy(t_list *matrix)
{
    t_list *m_copy;
    t_list *small;
    t_list *l;
    t_list *p;
    t_list *tmp;

    m_copy = NULL;
    tmp = m_copy;
    l = matrix;
    while (l)
    {
        printf("%c > ", (char)l->content_size);
        small = NULL;
        p = l->content;
        //printFromHead(p);
        while (p)
        {
            ft_lst_push_back(&small, ft_lstnew(p->content, p->content_size));
            //printf("%d ", *((int *)p->content));
            p = p->next;
            //printf("%p\n", p);
        }
        tmp = m_copy;
        while (tmp->next)
            tmp = tmp->next;
        tmp->content = small;
        tmp->next = NULL;
        printFromHead(tmp->content);
        //ft_lst_push_back(&m_copy, small);
        //printFromHead(small);
        //printf("\n");
        //printFromHead(small);
        //printf("\n");
        l = l->next;
    }
    while (m_copy)
    {
        printFromHead(m_copy->content);
        printf("\n");
        m_copy = m_copy->next;
    }
    return (m_copy);
}*/

static int		ft_tetr_check(t_list *res, t_list *content_from_matrix)
{
    t_list *l1;
    t_list *l2;

    //printf("%p > %p\n", res, res->content);
    //printf("FT_TETR_CHECK: %p\n", res);
    while (res)
    {
        l1 = res->content;
        l2 = content_from_matrix;
        printf("RES: \n");
        printFromHead(res->content);
        printf("CONTENT FROM MATRIX: \n");
        printFromHead(l2);
        while (l1 && l2)
        {
            //printf("l1 = %d, l2 = %d\n", *((int *)l1->content), *((int *)l2->content));
            if (*((int *)l1->content) + *((int *)l2->content) == 2)
                return (0);
            l1 = l1->next;
            l2 = l2->next;
        }
        res = res->next;
    }
    //printf("END OF FT_TETR_CHECK\n");
	return (1);
}

int    ft_algorithm(t_list *matrix, t_list *res)
{
    t_list *i;
    t_list *j;

    i = matrix;
    for (int ind = 0; ind < 50; ind++)
    {
        printf ("%c:\n", (char)i->content_size);
        //printFromHead(i->content);
        int check = ft_tetr_check(res, i->content);
        printf("CHECK = %d\n", check);
        printf("\n\n");
        if (check)
        {
            j = i->content;
            ft_lst_push_back(&res, ft_lstnew(i->content, sizeof(t_list)));
            while (i->next && i->content_size == i->next->content_size)
                i = i->next;  
            if (ft_algorithm(i->next, res))
                return (1);
            i = j->next;
        }
        else if (i->next && i->content_size == i->next->content_size)
            i = i->next;
        else 
            return (0);
    }
    return (1);
}