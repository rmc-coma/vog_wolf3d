/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newspriteanim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 07:49:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 02:16:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		w_assign_sprite_array(t_spriteanim *anim,
					t_spriteanimdata *info, t_screenpos pos, t_wolf *obj)
{
	char			*tmp;
	char			*tmp2;
	t_size			i;

	i = 0;
	while (i < info->n_sprites)
	{
		tmp2 = ft_itoa(i + 1);
		tmp = ft_strjoin(info->name, tmp2);
		anim->sprites[i] = w_newsprite(tmp,
								pos, info->keycolor, obj);
		free(tmp);
		free(tmp2);
		++i;
	}
}

t_spriteanim	*w_newspriteanim(char *name, t_screenpos pos,
								t_spriteanimdata info, t_wolf *obj)
{
	t_spriteanim	*anim;

	anim = (t_spriteanim *)malloc(sizeof(t_spriteanim));
	anim->name = name;
	anim->n_sprites = info.n_sprites;
	anim->sprites = (t_sprite **)malloc(sizeof(t_sprite *) *
										(info.n_sprites + 1));
	anim->sprites[info.n_sprites] = NULL;
	info.name = name;
	w_assign_sprite_array(anim, &info, pos, obj);
	anim->width = anim->sprites[0]->width;
	anim->height = anim->sprites[0]->height;
	anim->pos = pos;
	anim->timecode = info.timecode;
	anim->start_tick = 0;
	anim->iteration = 0;
	anim->keycolor = info.keycolor;
	return (anim);
}
