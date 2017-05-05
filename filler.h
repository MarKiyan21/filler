/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:42:00 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 16:47:03 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_map
{
	char		who;
	int			row;
	int			flag;
	int			pora;
	int			x_board;
	int			y_board;
	int			x_piece;
	int			y_piece;
	int			save_x;
	int			save_y;
	char		**board;
	char		**piece;
}				t_map;

void			add_line_bd(char *s, t_map *e);
void			add_line_pc(char *s, t_map *e);
int				check(t_map *e, int x, int y, char type);
void			find_board_coord(char *s, t_map *e);
void			find_piece_coord(char *s, t_map *e);
void			find_place(t_map *e, int *a, int *b);
void			find_player(char *s, t_map *e);
void			free_mass(char **mass);
int				free_space(t_map *e, int x, int y);
void			init_all_default(t_map *e);
int				length(t_map *e);
int				length_between(int x1, int y1, int x2, int y2);
int				main(void);
void			place(t_map *e);

#endif
