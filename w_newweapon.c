/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newweapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 07:48:08 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 04:27:58 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_setsounds(t_weapon *new, char *name)
{
	char	*tmp;

	tmp = ft_strjoin(name, "_draw");
	new->draw_sound = w_newsound(tmp);
	free(tmp);
	tmp = ft_strjoin(name, "-1");
	new->shoot_sound = w_newsound(tmp);
	free(tmp);
	tmp = ft_strjoin(name, "_clipout");
	new->clipout_sound = w_newsound(tmp);
	free(tmp);
	tmp = ft_strjoin(name, "_clipin");
	new->clipin_sound = w_newsound(tmp);
	free(tmp);
	tmp = ft_strjoin(name, "_slideback");
	new->slideb_sound = w_newsound(tmp);
	free(tmp);
	tmp = ft_strjoin(name, "_sliderelease");
	new->slider_sound = w_newsound(tmp);
	free(tmp);
}

t_weapon	*w_newweapon(char *name, t_spriteanimdata info, t_wolf *obj)
{
	t_weapon		*new;
	t_screenpos		sp;

	sp = w_init_screenpos(0, 0, w_vec2(8.0, 8.0), SPRITE_XRIGHT |
						SPRITE_YBOTTOM);
	new = (t_weapon *)malloc(sizeof(t_weapon));
	new->name = name;
	new->idle = w_newsprite(name, sp, info.keycolor, obj);
	new->clip_size = 17;
	new->clip_ammo = new->clip_size;
	new->stack_size = 68;
	new->stack_ammo = new->stack_size;
	new->cooldown = 300;
	new->shoot_anim = w_newspriteanim(name, sp, info, obj);
	new->reload_anim = w_newspriteanim(name, sp, info, obj);
	w_setsounds(new, name);
	new->reload_state = 0;
	return (new);
}
