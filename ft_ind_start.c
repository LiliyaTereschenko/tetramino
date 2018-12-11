/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ind_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:00:05 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 19:42:47 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_ind_start(char *buf)
{
	int i;
	int imin;
	int jmin;

	i = 0;
	imin = 5;
	jmin = 5;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i / 4 < imin)
				imin = i / 4;
			if (i % 4 < jmin)
				jmin = i % 4;
		}
		i++;
	}
	return (imin * 4 + jmin);
}
