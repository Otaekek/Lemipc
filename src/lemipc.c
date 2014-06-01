/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:34:11 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 17:42:45 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <unistd.h>

void		lemipc(int ac, char **av)
{
	t_info	*info;

	info = init(ac, av);
	print_board(info->game, 0);
	while (is_last(info))
			;
	while (42)
	{
		print_board(info->game, 1);
		sem_op(info->semid, -1);
		is_dead(info);
		if (is_last(info))
			shmclear(info, 1);
		find(info);
		sem_op(info->semid, 1);
		print_board(info->game, 1);
		usleep(TIMEOUT);
	}
	shmclear(info, 2);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_exit("Usage : ./lemipc <team>\n");
	ft_signals();
	lemipc(ac, av);
	return (0);
}
