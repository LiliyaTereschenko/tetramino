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
        i++;
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

static int  ft_check_str(char *s)
{
    int i;
    char *buf;
    int check;

    i = 0;
    if ((ft_strlen(s) + 1) % 21)
        return (0);
    while (s[i])
    {
        buf = ft_strsub(s, i, 20);
        check = ft_check_map(buf);
        free(buf);
        if (!check)
            return (0);
        i += 20;
        if (s[i] != '\n' && s[i])
            return (0);
        if (!s[i])
            return (1);
        i++;
    }
    return (1);
}

char        *ft_read_map(char *file_name)
{
    int     fd;
    int     ret;
    char    buf[BUFF_SIZE + 1];
    char    *s;
    char    *tmp;

    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (0);
    s = ft_strnew(0);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        tmp = s;
        buf[ret] = '\0';
        s = ft_strjoin(s, buf);
        free(tmp);
    }
    return (ft_check_str(s) ? s : NULL);
}
