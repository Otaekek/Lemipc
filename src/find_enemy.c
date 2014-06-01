/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:27:34 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 16:55:37 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void			find(t_info *info)
{
	t_coord		c;
	char	check;
	int		ret;

	if (info->game->players == 0)
		return ;
	c.x = 1;
	c.y = 1;
	check = 0;
	while (check != 2)
	{
		check = 0;
		if ((ret = v_find(info, c)) || (ret = h_find(info, c)))
			break ;
		if (info->x + c.x + 1 < info->game->width || info->x - (c.x + 1) >= 0)
			c.x++;
		else
			++check;
		if (info->y + c.y + 1 < info->game->height || info->y - (c.y + 1) >= 0)
			c.y++;
		else
			++check;
	}
	move(info, ret);
}
