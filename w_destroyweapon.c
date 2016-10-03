/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroyweapon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 07:48:08 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 01:12:25 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroyweapon(t_weapon **weapon)
{
	if (*weapon)
	{
		w_destroysprite(&((*weapon)->idle));
		w_destroyspriteanim(&((*weapon)->shoot_anim));
		w_destroyspriteanim(&((*weapon)->reload_anim));
		w_destroysound(&((*weapon)->draw_sound));
		w_destroysound(&((*weapon)->shoot_sound));
		w_destroysound(&((*weapon)->clipout_sound));
		w_destroysound(&((*weapon)->clipin_sound));
		w_destroysound(&((*weapon)->slideb_sound));
		w_destroysound(&((*weapon)->slider_sound));
	}
}
