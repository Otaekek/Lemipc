/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:51:31 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:51:44 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <time.h>

void				sem_op(int semid, int nb)
{
	struct sembuf	op;

	op.sem_num = 0;
	op.sem_op = nb;
	op.sem_flg = IPC_NOWAIT;
	semop(semid, &op, 1);
}

int					rand_max(int max)
{
	static int		i = 0;

	i += rand() % 100;
	srand(time(NULL) + i);
	return (rand() % max);
}
