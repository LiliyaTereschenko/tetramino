/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:52:03 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 19:47:30 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_create_list(char *buf, int map_size, int start)
{
	t_list	*beg;
	t_list	*l;
	int		i;
	char		n;

	i = 0;
	beg = NULL;
	n = 0;
	while (i < map_size * map_size)
	{
		l = ft_lstnew(&n, sizeof(char));
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
		l->content_size = (size_t)i;
		
		//printf("buf[i] = %c\n", buf[i]);
		if (buf[i] == '#')
		{
			//printf ("%d\n", i - ft_ind_start(buf) + start + i / 4 * (map_size - 4));
			l = ft_lst_at(beg, (unsigned int)(i - ft_ind_start(buf) + start + (i - ft_ind_start(buf)) / 4 * (map_size - 4)));
			*((char *)l->content) = 1;
			
			
		}
		i++;
	}
    //printf("ORIGIN LIST\n");
    //printFromHead(beg);
    //printf("\n===========================================\n");
	return (beg);
}
