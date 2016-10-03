/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_mainscene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 04:05:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 04:45:44 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	w_setwallsncols(t_size n_walls, int ceiling_color, int ground_color,
							t_wolf *obj)
{
	obj->level->n_walls = n_walls;
	obj->level->walls = (t_texture **)malloc(sizeof(t_texture *) *
											(n_walls + 1));
	obj->level->walls[0] = w_newtexture("wall_stones", 0x00BBBBBB);
	obj->level->walls[1] = w_newtexture("wall_bricks", 0x00FFBBBB);
	obj->level->walls[2] = w_newtexture("wall_stonebricks", 0x00FFDDDD);
	obj->level->walls[obj->level->n_walls] = NULL;
	obj->level->ceiling_color = ceiling_color;
	obj->level->ground_color = ground_color;
}

static void	w_setweapons(t_size n_weapons, t_wolf *obj)
{
	obj->player->n_weapons = n_weapons;
	obj->player->weapons = (t_weapon **)malloc(sizeof(t_weapon *) *
											(n_weapons + 1));
	obj->player->weapons[obj->player->n_weapons] = NULL;
	obj->player->weapons[0] = w_newweapon("glock18", w_spriteanimdata(4, 100,
														9961608), obj);
	obj->player->current_weapon = -1;
}

int			w_mainscene(t_wolf *obj)
{
	ft_putstr("Parsing map... ");
	obj->level->map = w_parse_map(open("./Maps/Main.w3d", O_RDONLY));
	ft_putendl("Done");
	obj->player = w_newplayer(1.5, 1.5, 0.0, 1);
	w_setwallsncols(3, 0x00151515, 0x00383838, obj);
	w_setweapons(1, obj);
	obj->crosshair = w_newsprite("crosshair", w_init_screenpos(0, 0, w_vec2(1.0,
					1.0), SPRITE_XCENTER | SPRITE_YCENTER), 16777215, obj);
	obj->render_textures = TRUE;
	SDL_SetRelativeMouseMode(!obj->idata->show_cursor);
	obj->loop = TRUE;
	ft_putendl("Starting loop");
	w_loop(obj);
	return (0);
}
