/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:19:54 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 16:17:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		length(t_map *e)
{
	int		x;
	int		y;
	char	enemy;

	if (e->who == 'O')
		enemy = 'X';
	else
		enemy = 'O';
	y = -1;
	while (++y < e->y_board)
	{
		x = -1;
		while (++x < e->x_board)
			if (e->board[y][x] == enemy && free_space(e, x, y))
			{
				e->save_x = x;
				e->save_y = y;
				return (1);
			}
	}
	return (0);
}

int		length_between(int x1, int y1, int x2, int y2)
{
	int	len1;
	int	len2;

	len1 = x2 - x1;
	len2 = y2 - y1;
	len1 = len1 * len1;
	len2 = len2 * len2;
	len1 = len1 + len2;
	return (len1);
}
