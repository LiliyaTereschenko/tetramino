/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:52:03 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 14:43:35 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_create_list(char *buf, int map_size, int start)
{
	t_list	*beg;
	t_list	*l;
	int		i;
	int		n;

	i = 0;
	beg = NULL;
	n = 0;
	while (i++ < map_size * map_size)
		ft_lst_push_back(&beg, (l = ft_lstnew(&n, sizeof(n))));
	i = 0;
	while (buf[i])
	{
		l->content_size = (size_t)i;
		if (buf[i] == '#')
		{
			l = ft_lst_at(beg, (unsigned int)(i - ft_ind_start(buf) + start +\
						(i - ft_ind_start(buf)) / 4 * (map_size - 4)));
			*((int *)l->content) = 1;
		}
		i++;
	}
	return (beg);
}
