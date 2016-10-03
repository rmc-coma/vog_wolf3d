/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_weapon_anim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 05:11:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:36:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_handle_weapon_anim(t_player *p, t_wolf *obj)
{
	t_weapon	*w;

	w = p->weapons[p->current_weapon];
	if (!p->is_shooting && !p->is_reloading)
	{
		w_draw_sprite(w->idle, obj);
		return ;
	}
	if (p->is_reloading)
	{
		if (w_draw_spriteanim(w->reload_anim, obj))
			p->is_reloading = FALSE;
	}
	else if (p->is_shooting)
	{
		if (w->shoot_anim->to_restart)
		{
			w->shoot_anim->start_tick = 0;
			w->shoot_anim->to_restart = FALSE;
		}
		if (w_draw_spriteanim(w->shoot_anim, obj))
			p->is_shooting = FALSE;
	}
}
