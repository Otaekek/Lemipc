/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msgq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:44:56 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 23:27:31 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

static int		is_lead(t_info *info)
{
	t_game		*game;
	int			i;
	int			j;

	game = info->game;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (i == info->y && j == info->x)
				continue ;
			if (game->map[i][j] == info->team)
				return (0);
		}
	}
	return (1);
}

static int		get_direction(t_info *info, t_coord coord)
{
	int			dx;
	int			dy;

	dx = coord.x - info->x;
	dy = coord.y - info->y;
	if (abs(dx) > abs(dy))
		return ((dx < 0 ? LEFT : RIGHT));
	return ((dy < 0 ? UP : DOWN));
}

void			tell(t_info *info, int y, int x)
{
	t_msgbuf	buf;

	buf.mtype = info->team;
	buf.coord.x = x;
	buf.coord.y = y;
	msgsnd(info->msgqid, &buf, sizeof(t_msgbuf) - sizeof(long), IPC_NOWAIT);
	if (x > -1)
	{
		printf("\033[%dA\033[K", info->game->height + 2);
		printf("\033[3%dmGo my minions !\033[0m\n", info->team % 7);
	}
}

void			listen_lead(t_info *info)
{
	t_msgbuf	buf;
	int			direction;
	int			size;

	direction = 0;
	size = sizeof(t_msgbuf) - sizeof(long);
	msgrcv(info->msgqid, &buf, size, info->team, IPC_NOWAIT);
	if (buf.coord.x == -1)
	{
		info->lead = 1;
		find(info);
		return ;
	}
	direction = get_direction(info, buf.coord);
	move(info, direction);
	printf("\033[%dA\033[K", info->game->height + 2);
	printf("\033[3%dmAy Sir !\033[0m\n", info->team % 7);
}

int				msgq_init(t_info *info, char *str)
{
	int			msgqid;

	info->lead = is_lead(info);
	if ((msgqid = msgget(get_key(str), 0666)) == -1)
	{
		if ((msgqid = msgget(get_key(str), 0666 | IPC_CREAT)) == -1)
			ft_exit("Can't msgget\n");
	}
	return (msgqid);
}
