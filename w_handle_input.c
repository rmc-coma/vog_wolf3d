/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:44:53 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 07:06:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_handle_released_key(t_wolf *obj)
{
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		obj->idata->shift = FALSE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_W)
		obj->idata->m_for = FALSE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_S)
		obj->idata->m_bac = FALSE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_A)
		obj->idata->m_sleft = FALSE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_D)
		obj->idata->m_sright = FALSE;
}

static void	w_handle_pressed_key(t_wolf *obj)
{
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_W)
		obj->idata->m_for = TRUE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_S)
		obj->idata->m_bac = TRUE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_A)
		obj->idata->m_sleft = TRUE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_D)
		obj->idata->m_sright = TRUE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		obj->idata->shift = TRUE;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_0)
		obj->player->current_weapon = -1;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_1)
		obj->player->current_weapon = 0;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_R)
		w_reload_weapon(obj->player);
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_GRAVE)
		obj->render_textures = !obj->render_textures;
	if (obj->idata->events->key.keysym.scancode == SDL_SCANCODE_LCTRL)
		SDL_SetRelativeMouseMode(!(obj->idata->show_cursor =
								!obj->idata->show_cursor));
}

static void	w_handle_pressed_button(t_wolf *obj)
{
	if (obj->idata->events->button.button == SDL_BUTTON_LEFT)
		w_use_weapon(obj->player);
}

void		w_handle_input(t_wolf *obj)
{
	if (obj->idata->events->window.event == SDL_WINDOWEVENT_CLOSE ||
		obj->idata->events->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		obj->loop = FALSE;
	if (obj->idata->events->type == SDL_KEYDOWN &&
		obj->idata->events->key.repeat == 0)
		w_handle_pressed_key(obj);
	if (obj->idata->events->type == SDL_KEYUP &&
		obj->idata->events->key.repeat == 0)
		w_handle_released_key(obj);
	if (obj->idata->events->type == SDL_MOUSEBUTTONDOWN)
		w_handle_pressed_button(obj);
	if (obj->idata->events->type == SDL_MOUSEMOTION)
		obj->idata->camera_movement = obj->idata->events->motion.xrel;
	w_handle_player_state(obj->player, obj->idata);
}
