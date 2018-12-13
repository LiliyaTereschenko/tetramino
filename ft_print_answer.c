/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:53:50 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:33:18 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_answer(char *answer, int map_size)
{
	int i;

	i = 0;
	while (answer[i])
	{
		ft_putchar(answer[i]);
		if (!((i + 1) % map_size))
			ft_putchar('\n');
		i++;
	}
}

void			ft_create_answer(t_list *res, int map_size)
{
	char	letter;
	char	*answer;
	int		i;
	t_list	*tmp;

	letter = 'A';
	answer = (char *)malloc(sizeof(char) * (map_size * map_size + 1));
	answer[map_size * map_size] = '\0';
	ft_memset(answer, '.', map_size * map_size);
	while (res)
	{
		tmp = res->content;
		i = 0;
		while (tmp)
		{
			if (*((int *)tmp->content) == 1)
				answer[i] = letter;
			tmp = tmp->next;
			i++;
		}
		letter++;
		res = res->next;
	}
	ft_print_answer(answer, map_size);
	free(answer);
}
