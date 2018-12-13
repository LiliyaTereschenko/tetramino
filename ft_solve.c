/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:56:04 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:26:41 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_pos_count(char *buf, int map_size)
{
	int start;
	int end;
	int width;
	int height;

	start = ft_ind_start(buf);
	end = ft_ind_end(buf);
	width = end % 4 - start % 4 + 1;
	height = end / 4 - start / 4 + 1;
	return ((map_size - width + 1) * (map_size - height + 1));
}

static void		ft_change_pose(int *start, int *end, int map_size)
{
	int	tmp;

	tmp = 0;
	if (*end % map_size == map_size - 1)
	{
		tmp = *end % map_size - *start % map_size + 1;
		*start += tmp;
		*end += tmp;
	}
	else
	{
		(*start)++;
		(*end)++;
	}
}

static int		ft_create_pose(t_list **matrix, char *buf, int map_size,\
					char letter)
{
	t_list	*l_matrix;
	int		pos_count;
	int		start;
	int		end;

	start = ft_ind_start(buf);
	end = ft_ind_end(buf);
	end = end - start + (end - start) / 4 * (map_size - 4);
	start = 0;
	pos_count = ft_pos_count(buf, map_size);
	if (pos_count <= 0)
		return (0);
	while (pos_count > 0)
	{
		l_matrix = ft_lstnew(ft_create_list(buf, map_size, start),\
						sizeof(t_list));
		ft_lst_push_back(matrix, l_matrix);
		l_matrix->content_size = (size_t)letter;
		pos_count--;
		ft_change_pose(&start, &end, map_size);
	}
	return (1);
}

static int		ft_solve_map_size(char *s, int map_count, t_list **res,\
					int map_size)
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
		s += 21;
		if (!ft_create_pose(&matrix, buf, map_size, letter))
			return (0);
		free(buf);
		letter++;
		i++;
	}
	if (ft_algorithm(matrix, res))
		return (1);
	while (matrix)
		ft_lst_del_last(&matrix);
	return (0);
}

void			ft_solve(char *s, int map_count)
{
	int		map_size;
	t_list	*res;

	map_size = ft_map_size(s);
	res = NULL;
	while (!ft_solve_map_size(s, map_count, &res, map_size))
		map_size++;
	ft_create_answer(res, map_size);
	free(s);
	while (res)
		ft_lst_del_last(&res);
}
