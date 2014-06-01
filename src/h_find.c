/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:44:04 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 17:16:18 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static int		h_find_right(t_info *info, t_coord c, int i)
{
	t_game		*game;
	int			found;

	game = info->game;
	if (info->y + c.y < game->height)
	{
		if (info->x + i < game->width)
		{
			found = game->map[info->y + c.y][info->x + i];
			if (found > -1 && found != info->team)
				return ((i > c.y ? RIGHT : DOWN));
		}
		if (info->x - i >= 0)
		{
			found = game->map[info->y + c.y][info->x - i];
			if (found > -1 && found != info->team)
				return ((i > c.y ? LEFT : DOWN));
		}
	}
	return (0);
}

static int		h_find_left(t_info *info, t_coord c, int i)
{
	t_game		*game;
	int			found;

	game = info->game;
	if (info->y - c.y >= 0)
	{
		if (info->x + i < game->width)
		{
			found = game->map[info->y - c.y][info->x + i];
			if (found > -1 && found != info->team)
				return ((i > c.y ? RIGHT : UP));
		}
		if (info->x - i >= 0)
		{
			found = game->map[info->y - c.y][info->x - i];
			if (found > -1 && found != info->team)
				return ((i > c.y ? LEFT : UP));
		}
	}
	return (0);
}

int		h_find(t_info *info, t_coord c)
{
	int			i;
	t_game		*game;
	int			found;

	game = info->game;
	i = -1;
	while (++i <= c.x)
	{
		if ((found = h_find_right(info, c, i)) > 0)
			return (found);
		if ((found = h_find_left(info, c, i)) > 0)
			return (found);
	}
	return (0);
}
