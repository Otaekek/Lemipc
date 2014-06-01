/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:58 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 16:21:14 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_fc_print.h>
#include <lemipc.h>
#include <stdlib.h>

static void		ft_handler(int s)
{
	if (s == SIGINT || s == SIGTERM || s == SIGQUIT || s == SIGABRT)
		shmclear(get_info(NULL), 2);
	else if (s == SIGKILL || s == SIGHUP)
		shmclear(get_info(NULL), 2);
	else if (s == SIGILL || s == SIGTRAP || s == SIGFPE || s == SIGBUS)
		shmclear(get_info(NULL), 3);
	else if (s == SIGSEGV || s == SIGSYS || s == SIGPIPE)
		shmclear(get_info(NULL), 3);
	else if (s == SIGTTIN || s == SIGTTOU || s == SIGXCPU || s == SIGXFSZ)
		shmclear(get_info(NULL), 3);
}


void			ft_signals(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGTERM, ft_handler);
	signal(SIGQUIT, ft_handler);
	signal(SIGABRT, ft_handler);
	signal(SIGKILL, ft_handler);
	signal(SIGHUP, ft_handler);
	signal(SIGILL, ft_handler);
	signal(SIGTRAP, ft_handler);
	signal(SIGFPE, ft_handler);
	signal(SIGBUS, ft_handler);
	signal(SIGSEGV, ft_handler);
	signal(SIGSYS, ft_handler);
	signal(SIGPIPE, ft_handler);
	signal(SIGTTIN, ft_handler);
	signal(SIGTTOU, ft_handler);
	signal(SIGXCPU, ft_handler);
	signal(SIGXFSZ, ft_handler);
}
