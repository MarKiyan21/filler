/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:32:47 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 14:36:08 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_line_bd(char *s, t_map *e)
{
	char	**buff;

	buff = ft_strsplit(s, ' ');
	if (buff[1] && !(ft_strcmp(buff[0], "Plateau") == 0))
	{
		e->board[e->row] = ft_strdup(buff[1]);
		e->row++;
	}
	free_mass(buff);
}

void	add_line_pc(char *s, t_map *e)
{
	e->piece[e->row] = ft_strdup(s);
	e->row++;
	if (e->row == e->y_piece)
	{
		e->row = 0;
		e->flag = 1;
		e->pora = 1;
	}
}
