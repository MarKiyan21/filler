/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:13:47 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/05/03 19:39:42 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../filler.h"

static void	print_result(char *line)
{
	if (line[3] == 'O')
	{
		printf("\033[22;32m\nRESULT:\n\033[0m");
		printf("%c%c%c%c  = ", 0xE2, 0xAD, 0x95, 0);
		printf("%d\n", ft_atoi(line + 10));
	}
	else
	{
		printf("%c%c%c%c  = ", 0xE2, 0x9D, 0x8E, 0);
		printf("%d\n", ft_atoi(line + 10));
		exit(0);
	}
}

static void	print_board(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while ((line[i] >= '0' && line[i] <= '9') || (line[i] == ' ' && i != 0))
			i++;
		if (line[i] == 'O' || line[i] == 'o')
			printf("%c%c%c%c ", 0xE2, 0xAD, 0x95, 0);
		else if (line[i] == 'X' || line[i] == 'x')
			printf("%c%c%c%c ", 0xE2, 0x9D, 0x8E, 0);
		else if (line[i] == '.')
			printf("%c ", line[i]);
		i++;
	}
	printf("\n");
}

static void	ft_check(char *line)
{
	if (line[0] == '#' || line[0] == 'l' || line[0] == '$' ||
		line[0] == 'P' || line[0] == '.' || line[0] == '*' ||
		line[0] == '<')
		return ;
	else if (line[0] == ' ')
	{
		usleep(80000);
		printf("%c[2J", 27);
	}
	else if (line[0] == '=')
		print_result(line);
	else
		print_board(line);
}

int			main(void)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_check(line);
		free(line);
	}
	return (0);
}
