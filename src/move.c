/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:50:01 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:50:34 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static int		v_move(t_info *info, int ret)
{
	t_game		*game;

	game = info->game;
	if (ret == UP)
	{
		if (info->y - 1 >= 0 && game->map[info->y - 1][info->x] == -1)
		{
			info->game->map[--info->y][info->x] = info->team;
			return (1);
		}
	}
	else if (ret == DOWN)
	{
		if (info->y + 1 < game->height && game->map[info->y + 1][info->x] == -1)
		{
			info->game->map[++info->y][info->x] = info->team;
			return (1);
		}
	}
	return (0);
}

static int		h_move(t_info *info, int ret)
{
	t_game		*game;

	game = info->game;
	if (ret == RIGHT)
	{
		if (info->x + 1 < game->width && game->map[info->y][info->x + 1] == -1)
		{
			info->game->map[info->y][++info->x] = info->team;
			return (1);
		}
	}
	else if (ret == LEFT)
	{
		if (info->x - 1 >= 0 && game->map[info->y][info->x - 1] == -1)
		{
			info->game->map[info->y][--info->x] = info->team;
			return (1);
		}
	}
	return (0);
}

void			move(t_info *info, int ret)
{
	if (ret == 0)
		return ;
	info->game->map[info->y][info->x] = -1;
	if (v_move(info, ret) || h_move(info, ret))
		return ;
	else
		move(info, rand_max(5));
	info->game->map[info->y][info->x] = info->team;
}
