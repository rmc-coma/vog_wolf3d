/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_newsprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:45:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 00:15:39 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sprite	*w_newsprite(char *name, t_screenpos pos, t_size keycolor,
						t_wolf *obj)
{
	SDL_Surface	*temp;
	t_sprite	*new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	new->name = w_pathcat(PATH_SPRITES, name, ".bmp");
	if ((temp = SDL_LoadBMP(new->name)) == NULL)
	{
		free(new->name);
		free(new);
		ft_putendl("Error : Failed to load sprite");
		return (NULL);
	}
	new->width = temp->w;
	new->height = temp->h;
	new->bpp = temp->format->BitsPerPixel;
	new->buffer = new->bpp == 24 ? w_parse_24b_surface(temp) :
		w_parse_8b_surface(temp);
	new->pos = w_get_screenpos(&pos, w_ivec2(new->width, new->height), obj);
	new->stretch = pos.stretch;
	new->keycolor = keycolor;
	SDL_FreeSurface(temp);
	return (new);
}
