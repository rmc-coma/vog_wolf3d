/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 03:49:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 04:38:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_bool	w_init_window(char *title, t_size win_width, t_size win_height,
							t_wolf *new)
{
	new->win_width = win_width;
	new->win_height = win_height;
	if (!(new->win_ptr = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_SHOWN)))
	{
		new->win_ptr = NULL;
		new->fb = NULL;
		return (FALSE);
	}
	if (!(new->fb = (t_fbuff *)malloc(sizeof(t_fbuff))))
	{
		new->fb = NULL;
		return (FALSE);
	}
	if (!(new->fb->framebuffer = SDL_GetWindowSurface(new->win_ptr)))
	{
		new->fb->framebuffer = NULL;
		return (FALSE);
	}
	new->fb->ptr = ((int *)(new->fb->framebuffer->pixels));
	SDL_FillRect(new->fb->framebuffer, NULL,
		SDL_MapRGB(new->fb->framebuffer->format, 0x00, 0x00, 0x00));
	return (TRUE);
}

static t_bool	w_init_audio(t_wolf *new)
{
	if (!(new->adata = (t_audiodata *)malloc(sizeof(t_audiodata))))
	{
		new->adata = NULL;
		return (FALSE);
	}
	if (!(new->adata->device = alcOpenDevice(NULL)))
	{
		new->adata->device = NULL;
		return (FALSE);
	}
	if (!(new->adata->context = alcCreateContext(new->adata->device, NULL)))
	{
		new->adata->context = NULL;
		return (FALSE);
	}
	if (!alcMakeContextCurrent(new->adata->context))
		return (FALSE);
	return (TRUE);
}

static t_bool	w_init_input(t_wolf *new)
{
	if (!(new->idata = (t_inputdata *)malloc(sizeof(t_inputdata))))
	{
		new->idata = NULL;
		return (FALSE);
	}
	if (!(new->idata->events = (SDL_Event *)malloc(sizeof(SDL_Event))))
	{
		new->idata->events = NULL;
		return (FALSE);
	}
	new->idata->camera_movement = 0;
	new->idata->show_cursor = FALSE;
	new->idata->shift = FALSE;
	new->idata->m_for = FALSE;
	new->idata->m_bac = FALSE;
	new->idata->m_sleft = FALSE;
	new->idata->m_sright = FALSE;
	return (TRUE);
}

static t_bool	w_init_render(t_wolf *new)
{
	if (!(new->rdata = (t_renderdata *)malloc(sizeof(t_renderdata))))
	{
		new->rdata = NULL;
		return (FALSE);
	}
	pthread_mutex_init(&(new->rdata->render_init_mutex), NULL);
	pthread_cond_init(&(new->rdata->render_init_cond), NULL);
	new->rdata->render_span.start = 0;
	new->rdata->render_span.end = 0;
	return (TRUE);
}

t_wolf			*w_init(t_size win_width, t_size win_height,
					t_size fov, char *title)
{
	t_wolf	*new;

	new = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		w_fexit("Error : Failed to initialize SDL", &(new));
	if (!(new = (t_wolf *)malloc(sizeof(t_wolf))))
		w_fexit("Error : Failed to allocate memory to main object", &(new));
	if (!(w_init_window(title, win_width, win_height, new)))
		w_fexit("Error : Failed to initialize window", &(new));
	if (!(w_init_audio(new)))
		w_fexit("Error : Failed to initialize audio", &(new));
	if (!(w_init_input(new)))
		w_fexit("Error : Failed to initialize input", &(new));
	if (!(w_init_render(new)))
		w_fexit("Error : Failed to initialize renderer", &(new));
	if (!(new->level = (t_level *)malloc(sizeof(t_level))))
		w_fexit("Error : Failed to allocate memory to level object", &(new));
	new->player = NULL;
	new->fov = fov;
	new->render_textures = TRUE;
	ft_putendl("Successfully initialized Wolf3D");
	return (new);
}
