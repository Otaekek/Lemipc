/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:25:13 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 18:56:49 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static int		compare_team(int team1, int team2)
{
	if (team1 == team2)
		return (1);
	return (0);
}

static void		test_cases(t_info *info, int x, int y, int team)
{
	int			check;

	check = 0;
	if (team == -1 || team == info->team)
		return ;
	if (y - 1 >= 0 && x - 1 >= 0)
		check += compare_team(team, info->game->map[y - 1][x - 1]);
	if (y - 1 >= 0)
		check += compare_team(team, info->game->map[y - 1][x]);
	if (y - 1 >= 0 && x + 1 < info->game->width)
		check += compare_team(team, info->game->map[y - 1][x + 1]);
	if (x - 1 >= 0)
		check += compare_team(team, info->game->map[y][x - 1]);
	if (x + 1 < info->game->width)
		check += compare_team(team, info->game->map[y][x + 1]);
	if (y + 1 < info->game->height && x - 1 >= 0)
		check += compare_team(team, info->game->map[y + 1][x - 1]);
	if (y + 1 < info->game->height)
		check += compare_team(team, info->game->map[y + 1][x]);
	if (y + 1 < info->game->height && x + 1 < info->game->width)
		check += compare_team(team, info->game->map[y + 1][x + 1]);
	if (check >= 2)
		shmclear(&info, 0);
}

void			is_dead(t_info *info)
{
	int			x;
	int			y;
	t_game		*game;

	game = info->game;
	x = info->x;
	y = info->y;
	if (y - 1 >= 0 && x - 1 >= 0)
		test_cases(info, x, y, game->map[y - 1][x - 1]);
	if (y - 1 >= 0)
		test_cases(info, x, y, game->map[y - 1][x]);
	if (y - 1 >= 0 && x + 1 < game->width)
		test_cases(info, x, y, game->map[y - 1][x + 1]);
	if (x - 1 >= 0)
		test_cases(info, x, y, game->map[y][x - 1]);
	if (x + 1 < game->width)
		test_cases(info, x, y, game->map[y][x + 1]);
	if (y + 1 < game->height && x - 1 >= 0)
		test_cases(info, x, y, game->map[y + 1][x - 1]);
	if (y + 1 < game->height)
		test_cases(info, x, y, game->map[y + 1][x]);
	if (y + 1 < game->height && x + 1 < game->width)
		test_cases(info, x, y, game->map[y + 1][x + 1]);
}

int				is_last(t_info *info)
{
	int			i;
	int			j;

	i = -1;
	while (++i < info->game->height)
	{
		j = -1;
		while (++j < info->game->width)
		{
			if (info->game->map[i][j] == -1)
				continue ;
			if (info->game->map[i][j] != info->team)
				return (0);
		}
	}
	return (1);
}
