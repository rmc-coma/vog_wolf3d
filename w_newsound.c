/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newsound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 23:53:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 04:12:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sound	*w_newsound(char *name)
{
	t_sound			*new;
	SDL_AudioSpec	tmp_spec;
	Uint8			*tmp_audio;
	Uint32			tmp_len;

	new = (t_sound *)malloc(sizeof(t_sound));
	new->name = w_pathcat(PATH_SOUNDS, name, ".wav");
	SDL_LoadWAV(new->name, &tmp_spec, &tmp_audio, &tmp_len);
	new->length = tmp_len * 1000 / (SDL_AUDIO_BITSIZE(tmp_spec.format) / 8)
		/ tmp_spec.channels / tmp_spec.freq;
	new->freq = tmp_spec.freq;
	if (tmp_spec.channels == 2)
		new->format = AL_FORMAT_STEREO16;
	else
		new->format = AL_FORMAT_MONO16;
	new->size = tmp_len;
	new->data = (ALvoid *)(tmp_audio);
	alGenBuffers(1, &(new->buffer));
	alBufferData(new->buffer, new->format, new->data, new->size, new->freq);
	alGenSources(1, &(new->source));
	alSourcei(new->source, AL_BUFFER, new->buffer);
	SDL_FreeWAV(tmp_audio);
	return (new);
}
