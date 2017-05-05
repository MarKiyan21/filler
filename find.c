/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:22:35 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 16:46:07 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_player(char *s, t_map *e)
{
	if (s[10] == '1')
		e->who = 'O';
	else if (s[10] == '2')
		e->who = 'X';
}

void	find_board_coord(char *s, t_map *e)
{
	char	**buff;

	buff = ft_strsplit(s, ' ');
	if (ft_strcmp(buff[0], "Plateau") == 0)
	{
		e->x_board = ft_atoi(buff[2]);
		e->y_board = ft_atoi(buff[1]);
		e->board = (char**)ft_memalloc(sizeof(char*) * (e->y_board + 1));
		e->row = 0;
		free_mass(buff);
	}
	else
	{
		free_mass(buff);
		return ;
	}
}

void	find_piece_coord(char *s, t_map *e)
{
	char	**buff;

	e->flag = 0;
	buff = ft_strsplit(s, ' ');
	if (ft_strcmp(buff[0], "Piece") == 0)
	{
		e->x_piece = ft_atoi(buff[2]);
		e->y_piece = ft_atoi(buff[1]);
		e->piece = (char**)ft_memalloc(sizeof(char*) * (e->y_piece + 1));
		e->row = 0;
		free_mass(buff);
	}
	else
	{
		free_mass(buff);
		return ;
	}
}

void	find_place(t_map *e, int *a, int *b)
{
	int		x;
	int		y;
	char	type;

	if (e->who == 'O')
		type = e->who;
	else
		type = 'X';
	y = -1;
	while (++y < e->y_board)
	{
		x = -1;
		while (++x < e->x_board)
			if (check(e, x, y, type))
			{
				if (((*a) == -1 && (*b) == -1) ||
				(length(e) && length_between((*b), (*a), e->save_x, e->save_y)
				> length_between(x, y, e->save_x, e->save_y)))
				{
					(*a) = y;
					(*b) = x;
				}
			}
	}
}
