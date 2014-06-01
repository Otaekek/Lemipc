/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:43:25 by Myrkskog          #+#    #+#             */
/*   Updated: 2014/06/01 21:14:18 by Myrkskog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_game
{
	int				players;
	int				width;
	int				height;
	int				map[HEIGHT][WIDTH];
}					t_game;

typedef struct		s_info
{
	int				shmid;
	int				semid;
	int				msgqid;
	int				team;
	char			lead;
	int				x;
	int				y;
	t_game			*game;
}					t_info;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_msgbuf
{
	long			mtype;
	t_coord			coord;
}					t_msgbuf;

#endif
