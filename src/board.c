/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:01:46 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 20:52:59 by Myrkskog         ###   ########.fr       */
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

void			print_board(t_game *game, char clean)
{
	int			i;
	int			j;
	char		*c;

	if (clean)
		clear_map(game);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] > -1)
			{
				c = ft_itoa(game->map[i][j] % 7);
				ft_putstr("\033[3");
				ft_putstr(c);
				ft_putstr("m");
				free(c);
			}
			ft_putstr("■ \033[0m");
		}
		ft_putstr("\b\n");
	}
	ft_putstr("\n");
}
