/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newtexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:45:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 23:12:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_size	**w_fillbuffer(SDL_Surface *temp)
{
	t_size		**buffer;
	int			i;
	int			j;

	buffer = (unsigned int **)malloc(sizeof(unsigned int *) * temp->h);
	i = 0;
	while (i < temp->h)
	{
		buffer[i] = (unsigned int *)malloc(sizeof(unsigned int) * temp->w);
		j = 0;
		while (j < temp->w)
		{
			buffer[i][j] =
		(t_size)((t_byte *)(temp->pixels))[(j + i * temp->w) * 3 + 2] << 16 |
		(t_size)((t_byte *)(temp->pixels))[(j + i * temp->w) * 3 + 1] << 8 |
		(t_size)((t_byte *)(temp->pixels))[(j + i * temp->w) * 3];
			++j;
		}
		++i;
	}
	return (buffer);
}

t_texture		*w_newtexture(char *name, int backcolor)
{
	SDL_Surface	*temp;
	t_texture	*new;

	new = (t_texture *)malloc(sizeof(t_texture));
	new->name = w_pathcat(PATH_TEXTURES, name, ".bmp");
	if (!(temp = SDL_LoadBMP(new->name)))
	{
		free(new->name);
		free(new);
		ft_putendl("Error : Failed to load texture");
		return (NULL);
	}
	new->width = temp->w;
	new->height = temp->h;
	new->backcolor = backcolor;
	new->buffer = w_fillbuffer(temp);
	SDL_FreeSurface(temp);
	return (new);
}
