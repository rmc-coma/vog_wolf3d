/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_deinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 03:56:00 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 01:12:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_deinit_renderdata(t_renderdata **rdata)
{
	int	i;

	if (*rdata)
	{
		if (N_THREADS)
		{
			pthread_mutex_destroy(&((*rdata)->render_init_mutex));
			pthread_cond_destroy(&((*rdata)->render_init_cond));
			i = 0;
			while (i < N_THREADS)
			{
				if ((*rdata)->render_thread[i])
					pthread_detach((*rdata)->render_thread[i]);
				++i;
			}
		}
		free(*rdata);
	}
}

static void	w_deinit_audiodata(t_audiodata **adata)
{
	if (*adata)
	{
		if ((*adata)->context)
		{
			alcMakeContextCurrent(NULL);
			alcDestroyContext((*adata)->context);
		}
		if ((*adata)->device)
			alcCloseDevice((*adata)->device);
		free(*adata);
	}
}

static void	w_deinit_inputdata(t_inputdata **idata)
{
	if (*idata)
	{
		if ((*idata)->events)
			free((*idata)->events);
		free(*idata);
	}
}

static void	w_deinit_framebuffer(t_fbuff **fb)
{
	if (*fb)
	{
		SDL_FreeSurface((*fb)->framebuffer);
		free(*fb);
	}
}

void		w_deinit(t_wolf **obj)
{
	if ((*obj)->win_ptr)
	{
		w_deinit_framebuffer(&((*obj)->fb));
		SDL_DestroyWindow((*obj)->win_ptr);
	}
	w_destroyplayer(&((*obj)->player));
	w_destroylevel(&((*obj)->level));
	w_deinit_inputdata(&((*obj)->idata));
	w_deinit_audiodata(&((*obj)->adata));
	w_deinit_renderdata(&((*obj)->rdata));
	SDL_Quit();
	free(*obj);
	ft_putendl("Successfully uninitialized Wolf3D");
}
