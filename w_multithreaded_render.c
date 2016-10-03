/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_multithreaded_render.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 03:12:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/03 09:28:47 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		w_multithreaded_render(t_wolf *obj)
{
	t_size	i;
	t_size	screen_range;

	screen_range = obj->win_width / N_THREADS;
	i = 0;
	while (i < N_THREADS)
	{
		obj->rdata->render_span.start = screen_range * i;
		obj->rdata->render_span.end = screen_range * (i + 1);
		pthread_create(&(obj->rdata->render_thread[i]), NULL, w_render_thread,
					obj);
		pthread_cond_wait(&(obj->rdata->render_init_cond),
						&(obj->rdata->render_init_mutex));
		++i;
	}
	i = 0;
	while (i < N_THREADS)
	{
		pthread_join(obj->rdata->render_thread[i], NULL);
		pthread_detach(obj->rdata->render_thread[i++]);
	}
	return (0);
}
