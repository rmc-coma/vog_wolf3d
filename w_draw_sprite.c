/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_draw_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 04:38:27 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:33:34 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_ivec2	w_draw_sprite_init(t_span *i, t_span *j, t_sprite *sprite,
								t_wolf *obj)
{
	t_ivec2	s_pos;

	s_pos.x = 0;
	s_pos.y = 0;
	i->end = sprite->pos.y + ((int)
							((double)sprite->height * sprite->stretch.y));
	j->end = sprite->pos.x + ((int)((double)sprite->width * sprite->stretch.x));
	if (i->end > (int)obj->win_height)
		i->end = obj->win_height;
	if (j->end > (int)obj->win_width)
		j->end = obj->win_width;
	if (sprite->pos.x < 0)
		sprite->pos.x = 0;
	if (sprite->pos.y < 0)
		sprite->pos.y = 0;
	i->start = sprite->pos.y;
	return (s_pos);
}

void			w_draw_sprite(t_sprite *sprite, t_wolf *obj)
{
	t_span	i;
	t_span	j;
	t_ivec2	s_pos;

	s_pos = w_draw_sprite_init(&i, &j, sprite, obj);
	while (i.start < i.end)
	{
		j.start = sprite->pos.x;
		s_pos.x = 0;
		while (j.start < j.end)
		{
			if (sprite->buffer[(int)(s_pos.y / sprite->stretch.y)]
				[(int)(s_pos.x / sprite->stretch.x)] != sprite->keycolor)
				obj->fb->ptr[j.start + i.start * obj->win_width] =
					sprite->buffer[(int)(s_pos.y / sprite->stretch.y)]
					[(int)(s_pos.x / sprite->stretch.x)];
			++j.start;
			++s_pos.x;
		}
		++i.start;
		++s_pos.y;
	}
}
