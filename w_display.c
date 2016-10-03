/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 00:49:41 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 01:01:24 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	w_darken(int color)
{
	return ((((color & 0x00FF0000) >> 1) & 0x00FF0000) |
			(((color & 0x0000FF00) >> 1) & 0x0000FF00) |
			(((color & 0x000000FF) >> 1) & 0x000000FF));
}

static void	w_outdraw(t_size i, t_size i_end, t_size column, t_wolf *obj)
{
	while (i)
		obj->fb->ptr[column + (i-- - 1) * obj->win_width] =
			obj->level->ceiling_color;
	while (i_end < obj->win_height)
		obj->fb->ptr[column + i_end++ * obj->win_width] =
			obj->level->ground_color;
}

static void	w_display_textured(t_size column, t_dda *d, int texture_id,
							t_wolf *obj)
{
	t_size			half_screen;
	t_size			i;
	t_size			i_end;
	t_size			range;
	t_texturedata	t;

	half_screen = obj->win_height >> 1;
	range = w_lround((double)obj->win_height / d->hit_dist);
	t.tex_range = range;
	if (range > half_screen)
		range = half_screen;
	i = half_screen - range;
	i_end = half_screen + range - 1;
	w_outdraw(i, i_end, column, obj);
	t.tex = obj->level->walls[texture_id];
	t.tex_step = (double)(t.tex->height - 1) / (double)((t.tex_range << 1) - 1);
	t.tex_column = d->hit_axis ?
		w_lround((d->hit_pos.x - (int)d->hit_pos.x) * (t.tex->width - 1)) :
		w_lround((d->hit_pos.y - (int)d->hit_pos.y) * (t.tex->width - 1));
	t.ind = t.tex_range - range;
	while (i < i_end)
		obj->fb->ptr[column + i++ * obj->win_width] = d->hit_axis ?
			t.tex->buffer[(int)(t.tex_step * t.ind++)][t.tex_column] :
			w_darken(t.tex->buffer[(int)(t.tex_step * t.ind++)][t.tex_column]);
}

static void	w_display_colored(t_size column, t_dda *d, int color, t_wolf *obj)
{
	t_size			half_screen;
	t_size			i;
	t_size			i_end;
	t_size			range;

	half_screen = obj->win_height >> 1;
	range = w_lround((double)obj->win_height / d->hit_dist);
	if (range > half_screen)
		range = half_screen;
	i = half_screen - range;
	i_end = half_screen + range;
	w_outdraw(i, i_end, column, obj);
	if (d->hit_axis)
		color = w_darken(color);
	while (i < i_end)
		obj->fb->ptr[column + i++ * obj->win_width] = color;
}

void		w_display(t_size column, t_dda *d, int texture_id, t_wolf *obj)
{
	if (obj->render_textures)
		w_display_textured(column, d, texture_id, obj);
	else
		w_display_colored(column, d, obj->level->walls[texture_id]->backcolor,
						obj);
}
