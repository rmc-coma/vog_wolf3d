/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_draw_spriteanim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 08:08:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/04/22 06:16:39 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	w_draw_spriteanim(t_spriteanim *anim, t_wolf *obj)
{
	int	current_tick;

	if (anim->start_tick == 0)
	{
		anim->start_tick = w_get_ticks();
		current_tick = 0;
		anim->iteration = 0;
	}
	else
	{
		current_tick = w_get_ticks() - anim->start_tick;
		anim->iteration = current_tick / anim->timecode;
	}
	if (anim->iteration >= anim->n_sprites)
	{
		anim->start_tick = 0;
		anim->iteration = 0;
		return (TRUE);
	}
	w_draw_sprite(anim->sprites[anim->iteration], obj);
	return (FALSE);
}
