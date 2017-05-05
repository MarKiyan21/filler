/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:31:06 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 16:39:53 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_map *e, int x, int y, char type)
{
	int	i;
	int	a;
	int	b;

	b = -1;
	i = 0;
	if ((e->x_board - x - e->x_piece) < 0 || (e->y_board - y - e->y_piece) < 0)
		return (0);
	while (++b < e->y_piece)
	{
		a = -1;
		while (++a < e->x_piece)
		{
			if (e->board[y + b][x + a] == type && e->piece[b][a] == '*')
				i++;
			else if (e->board[y + b][x + a] != '.' && e->piece[b][a] == '*')
				i = 2;
		}
	}
	if (i == 1)
		return (1);
	return (0);
}

int		free_space(t_map *e, int x, int y)
{
	int i;

	i = 0;
	if ((x - 2) >= 0 && e->board[y][x - 1] == '.' && e->board[y][x - 2] == '.')
		i++;
	if ((x + 2) < e->x_board && e->board[y][x + 1] == '.' &&
		e->board[y][x + 2] == '.')
		i++;
	if ((y - 2) >= 0 && e->board[y - 1][x] == '.' && e->board[y - 2][x] == '.')
		i++;
	if ((y + 2) < e->y_board && e->board[y + 1][x] == '.' &&
		e->board[y + 2][x] == '.')
		i++;
	if (i >= 2)
		return (1);
	return (0);
}
