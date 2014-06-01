/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:53:02 by sconso            #+#    #+#             */
/*   Updated: 2014/06/01 22:54:01 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# define WIDTH 20
# define HEIGHT 20
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define TIMEOUT 500000

# include <structs.h>
# include <sys/types.h>

/*
** board.c
*/
void		print_board(t_game *game, char clean);

/*
** clear.c
*/
void		shmclear(t_info **info, char state);

/*
** find_enemy.c
*/
void		find(t_info *info);

/*
** h_find.c
*/
int			h_find(t_info *info, t_coord c);

/*
** v_find.c
*/
int			v_find(t_info *info, t_coord c);

/*
** ft_errors.c
*/
void		ft_exit(char *str);
void		ft_assert(int test, char *str);

/*
** ft_msgq.c
*/
void		tell(t_info *info, int y, int x);
void		listen_lead(t_info *info);
int			msgq_init(t_info *info, char *str);

/*
** ft_signal.c
*/
void		ft_signals(void);

/*
** getters.c
*/
t_info		*get_info(t_info *info);
key_t		get_key(char *str);

/*
** init.c
*/
t_info		*init(int ac, char **av);

/*
** move.c
*/
void		move(t_info *info, int ret);

/*
** place.c
*/
void		place(t_info *info);

/*
** test_end.c
*/
void		is_dead(t_info *info);
int			is_last(t_info *info);

/*
** tools.c
*/
int			rand_max(int max);
void		sem_op(int semid, int nb);

#endif
