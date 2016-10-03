/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroysound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 23:53:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 21:53:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroysound(t_sound **sound)
{
	if (*sound)
	{
		free((*sound)->name);
		alSourceStop((*sound)->source);
		alSourcei((*sound)->source, AL_BUFFER, 0);
		alDeleteBuffers(1, &((*sound)->buffer));
		alDeleteSources(1, &((*sound)->source));
		free(*sound);
	}
}
