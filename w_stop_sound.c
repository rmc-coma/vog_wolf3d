/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_stop_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:39:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/04/23 06:48:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	w_stop_sound(t_sound *sound)
{
	sound->is_playing = FALSE;
	sound->start_tick = 0;
	alSourceStop(sound->source);
	return (TRUE);
}
