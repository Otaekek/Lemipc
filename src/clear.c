/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:28:52 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 21:13:42 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <ft_fc_print.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdlib.h>

void			shmclear(t_info **info, char state)
{
	print_board((*info)->game, 1);
	(*info)->game->players--;
	(*info)->game->map[(*info)->y][(*info)->x] = -1;
	tell(*info, -1, -1);
	if ((*info)->game->players <= 0)
	{
		shmctl((*info)->shmid, IPC_RMID, NULL);
		semctl((*info)->semid, 0, IPC_RMID, 0);
		msgctl((*info)->msgqid, IPC_RMID, NULL);
		ft_putendl("Destroyed SHM\n");
	}
	shmdt((*info)->game);
	free(*info);
	if (state == 0)
		ft_exit("Player killed !\n");
	if (state == 1)
		ft_exit("Team Won !\n");
	if (state == 2)
		ft_exit("Forced quit.\n");
	if (state == 3)
		ft_exit("Fatal error !\n");
	if (state == 4)
		ft_exit("Too much players for the map size !\n");
	ft_exit("WUt ?\n");
}
