/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_init_screenpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 05:03:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:46:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_screenpos	w_init_screenpos(int x_offset, int y_offset, t_vec2 stretch,
							t_byte flags)
{
	t_screenpos	new;

	new.offset.x = x_offset;
	new.offset.y = y_offset;
	new.stretch = stretch;
	new.flags = flags;
	return (new);
}
