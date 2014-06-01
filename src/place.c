/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:50:46 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:51:18 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <time.h>
#include <stdlib.h>

void				place(t_info *info)
{
	int				nb;
	t_game			*game;

	game = info->game;
	srand(time(NULL) + rand());
	nb = rand() % (game->width * game->height);
	while (game->map[nb / game->width][nb % game->width] != -1)
		nb = (rand()) % (game->width * game->height);
	info->x = nb % game->width;
	info->y = nb / game->width;
	game->map[info->y][info->x] = info->team;
}
