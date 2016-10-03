/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_play_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 05:14:10 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/04/23 04:05:37 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool		w_play_sound(t_sound *sound)
{
	if (sound->is_playing)
	{
		if (sound->start_tick >= sound->length + w_get_ticks())
		{
			sound->is_playing = FALSE;
			sound->start_tick = 0;
			return (TRUE);
		}
	}
	sound->is_playing = TRUE;
	sound->start_tick = w_get_ticks();
	alSourcePlay(sound->source);
	return (FALSE);
}
