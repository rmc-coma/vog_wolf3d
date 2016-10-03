/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroytexture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:45:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/03 08:07:45 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroytexture(t_texture **texture)
{
	t_size	i;

	if (*texture)
	{
		i = 0;
		while (i < (*texture)->height)
			free((*texture)->buffer[i++]);
		free((*texture)->buffer);
		free(*texture);
	}
}
