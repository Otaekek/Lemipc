/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:51:49 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:51:50 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static int		v_find_up(t_info *info, t_coord c, int i)
{
	t_game		*game;
	int			found;

	game = info->game;
	if (info->y - i >= 0)
	{
		found = game->map[info->y - i][info->x - c.x];
		if (found > -1 && found != info->team)
		{
			tell(info, info->y - i, info->x - c.x);
			return ((i > c.x ? UP : LEFT));
		}
	}
	if (info->y + i < game->height)
	{
		found = game->map[info->y + i][info->x - c.x];
		if (found > -1 && found != info->team)
		{
			tell(info, info->y + i, info->x - c.x);
			return ((i > c.x ? DOWN : LEFT));
		}
	}
	return (0);
}

static int		v_find_down(t_info *info, t_coord c, int i)
{
	t_game		*game;
	int			found;

	game = info->game;
	if (info->y - i >= 0)
	{
		found = game->map[info->y - i][info->x + c.x];
		if (found > -1 && found != info->team)
		{
			tell(info, info->y - i, info->x + c.x);
			return ((i > c.x ? UP : RIGHT));
		}
	}
	if (info->y + i < game->height)
	{
		found = game->map[info->y + i][info->x + c.x];
		if (found > -1 && found != info->team)
		{
			tell(info, info->y + i, info->x + c.x);
			return ((i > c.x ? DOWN : RIGHT));
		}
	}
	return (0);
}

int				v_find(t_info *info, t_coord c)
{
	int			i;
	t_game		*game;
	int			found;

	game = info->game;
	i = -1;
	while (++i <= c.y)
	{
		if (info->x - c.x >= 0)
		{
			if ((found = v_find_up(info, c, i)) > 0)
				return (found);
		}
		if (info->x + c.x < game->width)
		{
			if ((found = v_find_down(info, c, i)) > 0)
				return (found);
		}
	}
	return (0);
}
