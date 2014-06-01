/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:42:37 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:43:26 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <ft_fc_print.h>
#include <ft_fc_conversion.h>
#include <stdlib.h>

static void		clear_map(t_game *game)
{
	int		i;

	i = -1;
	while (++i <= game->height)
		ft_putstr("\r\033[K\033[1A\r");
}

static void		print_player(int team)
{
	char		*c;

	c = ft_itoa(team % 7);
	ft_putstr("\033[3");
	ft_putstr(c);
	ft_putstr("m");
	ft_putstr(c);
	ft_putstr("\033[0m ");
	free(c);
}

void			print_board(t_game *game, char clean)
{
	int			i;
	int			j;

	if (clean)
		clear_map(game);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] > -1)
				print_player(game->map[i][j]);
			else
				ft_putstr("o ");
		}
		ft_putstr("\b\n");
	}
	ft_putstr("\n");
}
