/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:36:40 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 16:47:56 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_all_default(t_map *e)
{
	e->who = 0;
	e->row = -1;
	e->flag = 1;
	e->pora = 0;
	e->x_board = 0;
	e->y_board = 0;
	e->x_piece = 0;
	e->y_piece = 0;
	e->save_x = 0;
	e->save_y = 0;
	e->board = NULL;
	e->piece = NULL;
}

void	free_mass(char **mass)
{
	int	i;

	i = -1;
	while (mass[++i])
		free(mass[i]);
	free(mass);
}

void	place(t_map *e)
{
	int	tmp;
	int	a;
	int	b;

	a = -1;
	b = -1;
	find_place(e, &a, &b);
	ft_putnbr(a);
	ft_putchar(' ');
	ft_putnbr(b);
	ft_putchar('\n');
	free_mass(e->board);
	free_mass(e->piece);
	tmp = e->who;
	init_all_default(e);
	e->who = tmp;
}

int		main(void)
{
	t_map	e;
	char	*line;

	init_all_default(&e);
	while (get_next_line(0, &line) > 0)
	{
		if (!e.who)
			find_player(line, &e);
		if (!e.x_board && !e.y_board)
			find_board_coord(line, &e);
		else if (e.flag && e.row >= 0 && e.row < e.y_board)
			add_line_bd(line, &e);
		if (e.row >= e.y_board)
			find_piece_coord(line, &e);
		else if (!(e.flag) && e.row >= 0 && e.row < e.y_piece)
			add_line_pc(line, &e);
		if (e.pora == 1)
			place(&e);
		free(line);
	}
	return (0);
}
