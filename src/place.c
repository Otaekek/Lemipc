/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:38:02 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 17:40:27 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <time.h>
#include <stdlib.h>

void				place(t_info *info)
{
	int 			i;
	int				nb;
	t_game			*game;

	i = 0;
	game = info->game;
	srand(time(NULL) + rand());
	nb = rand() % (game->width * game->height);
	while (game->map[nb / game->width][nb % game->width] != -1)
		nb = (rand()) % (game->width * game->height);
	info->x = nb % game->width;
	info->y = nb / game->width;
	game->map[info->y][info->x] = info->team;
}
