/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:56:45 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/07 12:56:47 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_count_connections(char *buf)
{
    int i;
    int c;

    i = 0;
    c = 0;
        
    while (buf[i])
    {
        if (buf[i] == '#')
        {
            if (i + 1 < BUFF_SIZE && buf[i + 1] == '#')
                c++;
            if (i - 1 >= 0 && buf[i - 1] == '#')
                c++;
            if (i + 5 < BUFF_SIZE && buf[i + 5] == '#')
                c++;
            if (i - 5 >= 0 && buf[i - 5] == '#')
                c++;
        }
    }
    return (c);
}

static int  ft_check_map(char *buf)
{
    int dot;
    int sharp;
    int i;

    dot = 0;
    sharp = 0;
    i = 0;
    while (buf[i])
    {
        if (buf[i] == '.')
            dot++;
        if (buf[i] == '#')
            sharp++;
        i++;  
    }
    if (dot == 12 && sharp == 4 && ft_count_connections(buf) >= 6)
        return (1);
    return (0);
}

int     ft_read_map(char *file_name)
{
    int     fd;
    int     ret;
    char    buf[BUFF_SIZE + 1];

    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (0);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (ft_check_map(buf))
            write;
    }
    close(fd);
    return(0);
}
