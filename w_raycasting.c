/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 04:21:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/03 09:09:48 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		w_initialize(double angle, t_dda *d)
{
	w_setvec2(&(d->ray.dir), w_dcos(angle), w_dsin(angle));
	w_setivec2(&(d->ray.mpos), (int)d->ray.pos.x, (int)d->ray.pos.y);
	w_setvec2(&(d->delta), sqrt(1 + w_sq(d->ray.dir.y) / w_sq(d->ray.dir.x)),
			sqrt(1 + w_sq(d->ray.dir.x) / w_sq(d->ray.dir.y)));
	if (d->ray.dir.x < 0)
	{
		d->step.x = -1;
		d->side.x = (d->ray.pos.x - d->ray.mpos.x) * d->delta.x;
	}
	else
	{
		d->step.x = 1;
		d->side.x = (d->ray.mpos.x + 1.0 - d->ray.pos.x) * d->delta.x;
	}
	if (d->ray.dir.y < 0)
	{
		d->step.y = -1;
		d->side.y = (d->ray.pos.y - d->ray.mpos.y) * d->delta.y;
	}
	else
	{
		d->step.y = 1;
		d->side.y = (d->ray.mpos.y + 1.0 - d->ray.pos.y) * d->delta.y;
	}
}

static void		w_step(t_dda *d)
{
	if (d->side.x < d->side.y)
	{
		d->side.x += d->delta.x;
		d->ray.mpos.x += d->step.x;
		d->hit_axis = 0;
	}
	else
	{
		d->side.y += d->delta.y;
		d->ray.mpos.y += d->step.y;
		d->hit_axis = 1;
	}
}

static void		w_process(t_dda *d)
{
	d->hit_dist = d->hit_axis ? ((double)(d->ray.mpos.y) - d->ray.pos.y +
		(1.0 - d->step.y) / 2.0) / d->ray.dir.y : ((double)(d->ray.mpos.x) -
		d->ray.pos.x + (1.0 - d->step.x) / 2.0) / d->ray.dir.x;
	d->hit_pos.x = d->ray.dir.x * d->hit_dist + d->ray.pos.x;
	d->hit_pos.y = d->ray.dir.y * d->hit_dist + d->ray.pos.y;
}

t_size			w_raycasting(double angle, t_dda *d, t_wolf *obj)
{
	t_size	enemies_found;
	t_size	limit;

	enemies_found = 0;
	w_initialize(angle, d);
	limit = CAST_LIMIT;
	while (limit--)
	{
		if (!limit)
			w_fexit("Error : Raycasting Failed", &obj);
		w_step(d);
		if (obj->level->map[d->ray.mpos.y][d->ray.mpos.x] > 0)
			break ;
		else if (obj->level->map[d->ray.mpos.y][d->ray.mpos.x] < 0)
			++enemies_found;
	}
	w_process(d);
	return (enemies_found);
}
