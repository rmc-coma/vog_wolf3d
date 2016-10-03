/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 04:07:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 07:07:00 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		w_loop(t_wolf *obj)
{
	unsigned long long int	start_tick;
	unsigned long long int	end_tick;
	t_size					i;

	i = 0;
	while (obj->loop)
	{
		start_tick = w_get_ticks();
		w_multithreaded_render(obj);
		if (obj->player->current_weapon != -1)
		{
			w_handle_weapon_anim(obj->player, obj);
			w_draw_sprite(obj->crosshair, obj);
		}
		SDL_UpdateWindowSurface(obj->win_ptr);
		if (SDL_PollEvent(obj->idata->events))
			w_handle_input(obj);
		w_handle_sound(obj);
		end_tick = w_get_ticks();
		w_handle_player_movement((double)(end_tick - start_tick) / 1000.0, obj);
		w_handle_camera_movement((double)(end_tick - start_tick) / 1000.0, obj);
	}
	return (0);
}
