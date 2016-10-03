/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_player_movement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 01:46:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 07:01:28 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_move(t_vec2 *next_pos, double orientation, double speed,
				double speed_multiplier)
{
	next_pos->x += w_dcos(orientation) * speed_multiplier * speed;
	next_pos->y += w_dsin(orientation) * speed_multiplier * speed;
}

void		w_handle_player_movement(double speed_mult, t_wolf *obj)
{
	double	speed;
	t_vec2	next_pos;

	speed = obj->idata->shift ? 3.0 : 1.0;
	next_pos.x = obj->player->pos.x;
	next_pos.y = obj->player->pos.y;
	if (obj->idata->m_for && !obj->idata->m_bac)
		w_move(&next_pos, obj->player->orientation, speed, speed_mult);
	if (obj->idata->m_bac && !obj->idata->m_for)
		w_move(&next_pos, obj->player->orientation + 180.0, 1.0, speed_mult);
	if (obj->idata->m_sleft)
		w_move(&next_pos, obj->player->orientation - 90.0, 1.0, speed_mult);
	if (obj->idata->m_sright)
		w_move(&next_pos, obj->player->orientation + 90.0, 1.0, speed_mult);
	if (!obj->level->map[(int)obj->player->pos.y][(int)(next_pos.x + 0.1)] &&
		!obj->level->map[(int)obj->player->pos.y][(int)(next_pos.x - 0.1)])
		obj->player->pos.x = next_pos.x;
	if (!obj->level->map[(int)(next_pos.y + 0.1)][(int)obj->player->pos.x] &&
		!obj->level->map[(int)(next_pos.y - 0.1)][(int)obj->player->pos.x])
		obj->player->pos.y = next_pos.y;
}
