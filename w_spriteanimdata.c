/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_spriteanimdata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 05:57:54 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 12:11:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_spriteanimdata	w_spriteanimdata(t_size n_sprites, t_size timecode,
									t_size keycolor)
{
	t_spriteanimdata	new;

	new.n_sprites = n_sprites;
	new.timecode = timecode;
	new.keycolor = keycolor;
	return (new);
}
