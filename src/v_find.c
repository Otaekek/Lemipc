/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:47:29 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 17:16:48 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static int		v_find_up(t_info *info, t_coord c, int i)
{
	t_game		*game;
	int			found;

	game = info->game;
	if (info->x - c.x >= 0)
	{
		if (info->y - i >= 0)
		{
			found = game->map[info->y - i][info->x - c.x];
			if (found > -1 && found != info->team)
				return ((i > c.x ? UP : LEFT));
		}
		if (info->y + i < game->height)
		{
			found = game->map[info->y + i][info->x - c.x];
			if (found > -1 && found != info->team)
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
	if (info->x + c.x < game->width)
	{
		if (info->y - i >= 0)
		{
			found = game->map[info->y - i][info->x + c.x];
			if (found > -1 && found != info->team)
				return ((i > c.x ? UP : RIGHT));
		}
		if (info->y + i < game->height)
		{
			found = game->map[info->y + i][info->x + c.x];
			if (found > -1 && found != info->team)
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
		if ((found = v_find_up(info, c, i)) > 0)
			return (found);
		if ((found = v_find_down(info, c, i)) > 0)
			return (found);
	}
	return (0);
}
