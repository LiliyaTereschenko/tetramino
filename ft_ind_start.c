/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ind_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:00:05 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 14:00:06 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_ind_start(char *buf)
{
    int i;
    int imin;
    int jmin;

    i = 0;
    imin = 6;
    jmin = 6;
    while (buf[i])
    {
        if (buf[i] == '#')
        {
            if (i / 5 < imin)
                imin = i / 5;
            if (i % 5 < jmin)
                jmin = i % 5;
        }
        i++;
    }
    return(imin * 5 + jmin);
}
