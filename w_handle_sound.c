/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_sound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 04:38:16 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/04/24 04:47:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_handle_sound(t_wolf *obj)
{
	t_player	*p;

	p = obj->player;
	if (p->is_running && !p->running_sound->is_playing)
		w_play_sound(p->running_sound);
	else if (!p->is_running && p->running_sound->is_playing)
		w_stop_sound(p->running_sound);
	if (p->is_walking && !p->is_running && !p->walking_sound->is_playing)
		w_play_sound(p->walking_sound);
	else if ((!p->is_walking && p->walking_sound->is_playing) || p->is_running)
		w_stop_sound(p->walking_sound);
}
