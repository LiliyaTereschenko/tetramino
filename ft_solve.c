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
	printf("BUF: %s\n", buf);
	width = end % map_size - start % map_size + 1;
	height = end / map_size - start / map_size + 1;
	return ((map_size - width + 1) * (map_size - height + 1));
}

static void		ft_create_pose(t_list **matrix, char *buf, int map_size, char letter)
{
    t_list	*l;
    t_list	*l_matrix;
    int		i;
    int		pos_count;
    int		start;
    int		end;
    int		tmp;

	end = ft_ind_end(buf) - ft_ind_start(buf);
	start = 0;
	i = 0;
	pos_count = ft_pos_count(buf, map_size);
	while (i < pos_count)
	{
		l = ft_create_list(buf, map_size, start);
		l_matrix = ft_lstnew(l, sizeof(t_list));
		ft_lst_push_back(matrix, l_matrix);
		l_matrix->content_size = (size_t)letter;
		i++;
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
}

static int    ft_solve_map_size(char *s, int map_count, t_list *res, int map_size)
{
	t_list	*matrix;
	int		i;
	char	letter;
    char	*buf;

	letter = 'A';
	i = 0;
	matrix = NULL;
	while (i < map_count)
	{
		buf = ft_drop_n(s);
		//printf("BUF: %s\n", buf);
		s += 21;
		ft_create_pose(&matrix, buf, map_size, letter);
		free(buf);
		letter++;
		i++;
	}
	if (ft_algorithm(matrix, res))
		return (1);
	return (0);
}

void	ft_solve(char *s, int map_count)
{
	int map_size;
	t_list *res;
	char letter;

	map_size = ft_map_size(s);
	res = NULL;
	while (!ft_solve_map_size(s, map_count, res, map_size))
		map_size++;
	letter = 'A';
	if (!res)
		printf("\nRES = NULL\n");
	else
		while(res)
		{
			printf("%c:\n", letter);
			letter++;
			printFromHead(res->content);
			res = res->next;
		}
}