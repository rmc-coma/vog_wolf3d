/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroysprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:45:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 21:57:11 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroysprite(t_sprite **sprite)
{
	t_size	i;

	if (*sprite)
	{
		free((*sprite)->name);
		i = 0;
		while (i < (*sprite)->height)
			free((*sprite)->buffer[i++]);
		free((*sprite)->buffer);
		free(*sprite);
	}
}
