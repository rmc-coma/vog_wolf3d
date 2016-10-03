/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroyspriteanim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 07:49:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 22:01:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroyspriteanim(t_spriteanim **anim)
{
	if (*anim)
	{
		while ((*anim)->n_sprites--)
			w_destroysprite(&((*anim)->sprites[(*anim)->n_sprites]));
		free((*anim)->sprites);
		free(*anim);
	}
}
