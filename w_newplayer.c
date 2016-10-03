/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 00:45:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:47:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player	*w_newplayer(double x_pos, double y_pos, double orientation,
						t_size n_weapons)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	new->pos.x = x_pos;
	new->pos.y = y_pos;
	new->orientation = orientation;
	new->n_weapons = n_weapons;
	new->is_reloading = FALSE;
	new->is_shooting = FALSE;
	new->is_walking = FALSE;
	new->is_running = FALSE;
	new->walking_sound = w_newsound("walking");
	new->running_sound = w_newsound("running");
	return (new);
}
