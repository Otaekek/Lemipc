/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:41:47 by sconso            #+#    #+#             */
/*   Updated: 2014/05/31 14:49:11 by Myrkskog         ###   ########.fr       */
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
