/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_render_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 06:17:52 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 01:03:24 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_span	w_render_thread_init(t_wolf *obj)
{
	t_span	i;

	i.start = obj->rdata->render_span.start;
	i.end = obj->rdata->render_span.end;
	pthread_mutex_lock(&(obj->rdata->render_init_mutex));
	pthread_cond_signal(&(obj->rdata->render_init_cond));
	pthread_mutex_unlock(&(obj->rdata->render_init_mutex));
	return (i);
}

void			*w_render_thread(void *arg)
{
	t_wolf		*obj;
	t_span		i;
	double		angle;
	double		j;
	t_dda		d;

	obj = (t_wolf *)(arg);
	i = w_render_thread_init(obj);
	angle = (double)(obj->fov) /
		(double)(obj->win_width);
	j = -((double)(obj->fov / 2.0)) + obj->player->orientation + angle *
		i.start;
	w_setvec2(&(d.ray.pos), obj->player->pos.x, obj->player->pos.y);
	while (i.start < i.end)
	{
		w_raycasting(j, &d, obj);
		d.hit_dist *= w_dcos(j - obj->player->orientation);
		w_display(i.start, &d,
				obj->level->map[d.ray.mpos.y][d.ray.mpos.x] - 1, obj);
		j += angle;
		++(i.start);
	}
	pthread_exit(NULL);
}
