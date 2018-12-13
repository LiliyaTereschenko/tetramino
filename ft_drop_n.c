/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:09:47 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:33:55 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_drop_n(char *s)
{
	char *tmp1;
	char *tmp2;
	char *tmp3;
	char *tmp4;
	char *buf;

	tmp1 = ft_strsub(s, 0, 4);
	tmp2 = ft_strsub(s, 5, 4);
	tmp3 = ft_strsub(s, 10, 4);
	tmp4 = ft_strsub(s, 15, 4);
	buf = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	tmp1 = buf;
	free(tmp2);
	buf = ft_strjoin(buf, tmp3);
	free(tmp1);
	free(tmp3);
	tmp1 = buf;
	buf = ft_strjoin(buf, tmp4);
	free(tmp1);
	free(tmp4);
	return (buf);
}
