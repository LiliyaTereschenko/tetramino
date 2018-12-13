/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:21:37 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:39:37 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_tetr_check(t_list *res, t_list *content_from_matrix)
{
	t_list *l1;
	t_list *l2;

	while (res)
	{
		l1 = res->content;
		l2 = content_from_matrix;
		while (l1 && l2)
		{
			if (*((int *)l1->content) + *((int *)l2->content) == 2)
				return (0);
			l1 = l1->next;
			l2 = l2->next;
		}
		res = res->next;
	}
	return (1);
}

int			ft_algorithm(t_list *matrix, t_list **res)
{
	t_list	*i;
	t_list	*j;

	i = matrix;
	while (i)
	{
		if (ft_tetr_check(*res, i->content))
		{
			j = i;
			ft_lst_push_back(res, ft_lstnew(i->content, sizeof(t_list)));
			while (i->next && i->content_size == i->next->content_size)
				i = i->next;
			if (!(i->next) || ft_algorithm(i->next, res))
				return (1);
			ft_lst_del_last(res);
			i = j->next;
			if (!i || i->content_size != j->content_size)
				return (0);
		}
		else if (i->next && i->content_size == i->next->content_size)
			i = i->next;
		else
			return (0);
	}
	return (0);
}
