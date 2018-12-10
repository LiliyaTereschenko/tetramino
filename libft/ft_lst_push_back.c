/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:16:59 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 12:17:02 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_list, t_list *new)
{
	t_list *current;

	current = *begin_list;
	if (current == 0)
		*begin_list = new;
	else
	{
		while (current->next != 0)
			current = current->next;
		current->next = new;
	}
}
