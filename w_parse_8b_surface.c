/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_parse_8b_surface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 02:05:38 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 11:53:54 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_size	**w_parse_8b_surface(SDL_Surface *surf)
{
	t_size	**buffer;
	int		i;
	int		j;

	buffer = (unsigned int **)malloc(sizeof(unsigned int *) * surf->h);
	i = 0;
	while (i < surf->h)
	{
		buffer[i] = (unsigned int *)malloc(sizeof(unsigned int) * surf->w);
		j = 0;
		while (j < surf->w)
		{
			buffer[i][j] =
				((((((t_byte *)(surf->pixels))[j + i * surf->w] & 192) >> 6)
				* 85) << 16) |
				((((((t_byte *)(surf->pixels))[j + i * surf->w] & 48) >> 4)
				* 85) << 8) |
				(((((t_byte *)(surf->pixels))[j + i * surf->w] & 12) >> 2)
				* 85);
			++j;
		}
		++i;
	}
	return (buffer);
}
