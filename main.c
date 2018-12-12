/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:42:20 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 19:21:28 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void printFromHead(t_list *list) 
{
	if (list)
	{
		ft_putnbr(*((int *)list->content));
		if (!(list->content))
			printf("LIST CONTENT = NULL\n");
		ft_putstr(" ");
		printFromHead(list->next);
	}
	else
		printf("\n");
}

int	main(int argc, char **argv)
{
	char *s;
	int map_count;

	if (argc == 2)
	{
		if ((s = ft_read_map(argv[1])))
		{
			map_count = ft_map_count(s);
			(map_count < 1 || map_count > 27) ? ft_error() : ft_solve(s, map_count);
		}
		else 
			ft_error();
	}
	else
		ft_usage();
	return (0);
}
