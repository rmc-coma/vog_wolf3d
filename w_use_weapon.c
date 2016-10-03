/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_use_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:59:17 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 06:53:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	w_use_weapon(t_player *p)
{
	t_weapon	*w;

	if (p->current_weapon < 0)
		return (FALSE);
	w = p->weapons[p->current_weapon];
	if (w->clip_ammo > 0)
	{
		if (w_get_ticks() - w->shoot_anim->start_tick < w->cooldown)
			return (FALSE);
		if (p->is_shooting)
			w->shoot_anim->to_restart = TRUE;
		else
			p->is_shooting = TRUE;
		w_play_sound(w->shoot_sound);
		--(w->clip_ammo);
		return (TRUE);
	}
	return (FALSE);
}

/*
**		d.ray.pos.x = obj->player->pos.x;
**		d.ray.pos.y = obj->player->pos.y;
**      printf("Hit at %g %g from %g %g %g, dist %g\n", d.hit_pos.x,
**		d.hit_pos.y, obj->player->pos.x,
**             obj->player->pos.y, obj->player->orientation, d.hit_dist);
*/
