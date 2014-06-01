/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:49:44 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:55:18 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <unistd.h>

void			lemipc(int ac, char **av)
{
	t_info		*info;

	info = init(ac, av);
	print_board(info->game, 0);
	while (is_last(info))
		;
	while (42)
	{
		sem_op(info->semid, -1);
		print_board(info->game, 1);
		is_dead(info);
		if (is_last(info))
			shmclear(&info, 1);
		if (info->lead)
			find(info);
		else
			listen_lead(info);
		print_board(info->game, 0);
		sem_op(info->semid, 1);
		usleep(TIMEOUT);
	}
	shmclear(&info, 2);
}

int				main(int ac, char **av)
{
	if (ac < 2)
		ft_exit("Usage : ./lemipc <team>\n");
	ft_signals();
	lemipc(ac, av);
	return (0);
}
