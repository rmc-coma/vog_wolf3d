/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_reload_weapon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 02:26:54 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 06:55:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	w_reload_weapon(t_player *p)
{
	t_weapon	*w;

	if (p->current_weapon < 0)
		return (FALSE);
	w = p->weapons[p->current_weapon];
	if (w->stack_ammo && w->clip_ammo < w->clip_size)
	{
		if (!p->is_reloading)
		{
			w->clip_ammo = w->clip_size > w->stack_ammo ? w->stack_ammo :
				w->clip_size;
			w->stack_ammo -= w->clip_ammo;
			w->reload_state = 0;
			p->is_reloading = TRUE;
		}
		return (TRUE);
	}
	return (FALSE);
}
