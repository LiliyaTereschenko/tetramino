/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:56:04 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 19:30:12 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_drop_n(char *s)
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
	tmp1 = buf;
	buf = ft_strjoin(buf, tmp3);
	free(tmp1);
	tmp1 = buf;
	buf = ft_strjoin(buf, tmp4);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	free(tmp4);
	return (buf);
}

static int		ft_pos_count(char *buf, int map_size)
{
	int start;
	int end;
	int width;
	int height;

	start = ft_ind_start(buf);
	end = ft_ind_end(buf);
	//printf("BUF: %s\n", buf);
	//printf("start = %d, end = %d\n", start, end);
	width = end % 4 - start % 4 + 1;
	height = end / 4 - start / 4 + 1;
	//printf("width = %d, height = %d\n", width, height);
	return ((map_size - width + 1) * (map_size - height + 1));
}

static int		ft_create_pose(t_list **matrix, char *buf, int map_size, char letter)
{
    t_list	*l_matrix;
    int		pos_count;
    int		start;
    int		end;
    int		tmp;

	
	start = ft_ind_start(buf);
	end = ft_ind_end(buf);
	end = end - start + (end - start) / 4 * (map_size - 4);
	start = 0;
	pos_count = ft_pos_count(buf, map_size);
	//printf("<<<<<<<<<<<<< %d\n", pos_count);
	if (pos_count <= 0)
		return (0);
	while (pos_count > 0)
	{
		l_matrix = ft_lstnew(ft_create_list(buf, map_size, start), sizeof(t_list));
		ft_lst_push_back(matrix, l_matrix);
		l_matrix->content_size = (size_t)letter;
		pos_count--;
		if (end % map_size == map_size - 1)
		{
			tmp = end % map_size - start % map_size + 1;
			start += tmp;
			end += tmp;
		}
		else
		{
			start++;
			end++;
		}
	}
	return (1);
}

static int    ft_solve_map_size(char *s, int map_count, t_list **res, int map_size)
{
	t_list	*matrix;
	int		i;
	char	letter;
    char	*buf;

	letter = 'A';
	i = 0;
	matrix = NULL;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>      map size = %d\n", map_size);
	while (i < map_count)
	{
		buf = ft_drop_n(s);
		//printf("BUF: %s\n", buf);
		s += 21;
		if (!ft_create_pose(&matrix, buf, map_size, letter))
			return (0);
		free(buf);
		letter++;
		i++;
	}
	if (!matrix)
		printf("NULL MATRIX\n");
	t_list *l = matrix;
    while(l)
    {
        ft_putstr("> ");
        printFromHead(l->content);
        l = l->next;
    }
	if (ft_algorithm(matrix, res))
		return (1);
	//printf("=========================\n");
	//while (matrix)
		//ft_lst_del_last(&matrix);
	//matrix = NULL;
	return (0);
}

void	ft_solve(char *s, int map_count)
{
	int map_size;
	t_list *res;
	char letter;

	map_size = ft_map_size(s);
	res = NULL;
	//int r = ft_solve_map_size(s, map_count, &res, map_size);
	//printf("V ITOGE == %d\n", r);
	while (!ft_solve_map_size(s, map_count, &res, map_size))
	{
		printf("MAP_SIZE++;\n");
		map_size++;
	}
	letter = 'A';
	if (!res)
		printf("\nRES = NULL\n");
	else
	{
		printf("\n====== RESULT =====\n");
		while(res)
		{
			printf("%c:\n", letter);
			letter++;
			printFromHead(res->content);
			res = res->next;
		}
	}
}