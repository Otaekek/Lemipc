/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:46:08 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:46:08 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>
#include <sys/ipc.h>
#include <stdlib.h>

key_t		get_key(char *str)
{
	return (ftok(str, 42));
}

t_info		*get_info(t_info *info)
{
	static t_info	*sinfo = NULL;

	if (info)
		sinfo = info;
	return (sinfo);
}
