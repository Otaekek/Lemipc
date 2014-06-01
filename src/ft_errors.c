/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:44:44 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:44:45 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_print.h>
#include <stdlib.h>

void			ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

void			ft_assert(int test, char *str)
{
	if (!test)
		ft_exit(str);
}
