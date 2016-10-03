/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_get_screenpos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 09:14:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:35:01 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_check_screenpos(t_ivec2 *new, t_ivec2 half_size, int ww, int wh)
{
	if (new->x + half_size.x * 2 > ww)
		new->x = ww - half_size.x * 2;
	else if (new->x - half_size.x * 2 < 0)
		new->x = 0;
	if (new->y + half_size.y * 2 > wh)
		new->y = wh - half_size.y * 2;
	else if (new->y - half_size.y * 2 < 0)
		new->y = 0;
}

t_ivec2		w_get_screenpos(t_screenpos *pos, t_ivec2 sprite_size, t_wolf *obj)
{
	int		ww;
	int		wh;
	t_ivec2	half_size;
	t_ivec2	new;

	ww = obj->win_width;
	wh = obj->win_height;
	half_size.x = (int)(sprite_size.x * pos->stretch.x) / 2;
	half_size.y = (int)(sprite_size.y * pos->stretch.y) / 2;
	if (pos->flags & 2)
		new.x = ww + pos->offset.x - half_size.x;
	else if (pos->flags & 1)
		new.x = ww / 2 + pos->offset.x - half_size.x;
	else
		new.x = pos->offset.x - half_size.x;
	if (pos->flags & 32)
		new.y = wh + pos->offset.y - half_size.y;
	else if (pos->flags & 16)
		new.y = wh / 2 + pos->offset.y - half_size.y;
	else
		new.y = pos->offset.y - half_size.y;
	w_check_screenpos(&new, half_size, ww, wh);
	return (new);
}
