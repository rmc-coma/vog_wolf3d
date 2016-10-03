/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_camera_movement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 04:15:08 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 07:02:41 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_handle_camera_movement(double speed_multiplier, t_wolf *obj)
{
	if (obj->idata->show_cursor)
		return ;
	obj->player->orientation += obj->idata->camera_movement *
		speed_multiplier * SENSITIVITY;
	if (obj->player->orientation >= 360.0)
		obj->player->orientation -= 360.0;
	else if (obj->player->orientation < 0.0)
		obj->player->orientation += 360.0;
	obj->idata->camera_movement = 0;
}
