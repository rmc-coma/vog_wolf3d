/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 03:31:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 06:54:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <time.h>

# include "SDL2/Headers/SDL.h"
# include "OpenAL/Headers/OpenAL.h"

# include "libft/include/libft.h"
# include "libft/include/get_next_line.h"

# define FALSE	0
# define TRUE	!FALSE

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define FOV			60

# define SENSITIVITY	2

# define N_THREADS		8

# define CAST_LIMIT		10000

# define PATH_SOUNDS	"./Sounds/"
# define PATH_SPRITES	"./Sprites/"
# define PATH_TEXTURES	"./Textures/"

# define SPRITE_XLEFT	0
# define SPRITE_XCENTER	1
# define SPRITE_XRIGHT	2
# define SPRITE_YTOP	0
# define SPRITE_YCENTER	16
# define SPRITE_YBOTTOM	32

typedef unsigned char	t_bool;
typedef unsigned int	t_size;
typedef unsigned char	t_byte;

typedef struct			s_vec2
{
	double			x;
	double			y;
}						t_vec2;

typedef struct			s_ivec2
{
	int				x;
	int				y;
}						t_ivec2;

typedef struct			s_span
{
	int				start;
	int				end;
}						t_span;

typedef struct			s_screenpos
{
	t_ivec2			offset;
	t_vec2			stretch;
	t_byte			flags;
}						t_screenpos;

typedef struct			s_fbuff
{
	SDL_Surface		*framebuffer;
	int				*ptr;
}						t_fbuff;

typedef	struct			s_ray
{
	t_vec2			pos;
	t_ivec2			mpos;
	t_vec2			dir;
}						t_ray;

typedef struct			s_dda
{
	t_ray			ray;
	t_vec2			step;
	t_vec2			side;
	t_vec2			delta;
	double			hit_dist;
	t_bool			hit_axis;
	t_vec2			hit_pos;
}						t_dda;

typedef struct			s_renderdata
{
	pthread_t		render_thread[N_THREADS];
	t_span			render_span;
	pthread_mutex_t	render_init_mutex;
	pthread_cond_t	render_init_cond;
}						t_renderdata;

typedef struct			s_inputdata
{
	SDL_Event		*events;
	int				camera_movement;
	t_bool			show_cursor;
	t_bool			shift;
	t_bool			m_for;
	t_bool			m_bac;
	t_bool			m_sleft;
	t_bool			m_sright;
}						t_inputdata;

typedef struct			s_sound
{
	char			*name;
	ALuint			buffer;
	ALenum			format;
	ALvoid			*data;
	ALsizei			size;
	ALsizei			freq;
	ALuint			source;
	t_bool			is_playing;
	t_size			length;
	t_size			start_tick;
}						t_sound;

typedef struct			s_audiodata
{
	ALCdevice		*device;
	ALCcontext		*context;
}						t_audiodata;

typedef struct			s_texture
{
	char			*name;
	t_size			**buffer;
	t_size			width;
	t_size			height;
	int				backcolor;
}						t_texture;

typedef struct			s_texturedata
{
	t_texture		*tex;
	t_size			tex_range;
	double			tex_step;
	t_size			tex_column;
	t_size			ind;
}						t_texturedata;

typedef struct			s_sprite
{
	char			*name;
	t_size			**buffer;
	t_size			bpp;
	t_size			width;
	t_size			height;
	t_ivec2			pos;
	t_vec2			stretch;
	t_size			keycolor;
}						t_sprite;

typedef struct			s_spriteanimdata
{
	char			*name;
	t_size			n_sprites;
	t_size			timecode;
	t_size			keycolor;
}						t_spriteanimdata;

typedef struct			s_spriteanim
{
	char			*name;
	t_sprite		**sprites;
	t_size			n_sprites;
	t_screenpos		pos;
	t_size			width;
	t_size			height;
	t_size			timecode;
	t_size			start_tick;
	t_size			iteration;
	t_bool			to_restart;
	t_size			keycolor;
}						t_spriteanim;

typedef struct			s_weapon
{
	char			*name;
	t_size			clip_ammo;
	t_size			clip_size;
	t_size			stack_ammo;
	t_size			stack_size;
	t_size			cooldown;
	t_sprite		*idle;
	t_spriteanim	*shoot_anim;
	t_spriteanim	*reload_anim;
	t_sound			*draw_sound;
	t_sound			*shoot_sound;
	t_sound			*clipout_sound;
	t_sound			*clipin_sound;
	t_sound			*slideb_sound;
	t_sound			*slider_sound;
	int				reload_state;
}						t_weapon;

typedef struct			s_player
{
	t_vec2			pos;
	double			orientation;
	int				current_weapon;
	t_bool			is_shooting;
	t_bool			is_reloading;
	t_bool			is_walking;
	t_bool			is_running;
	t_sound			*walking_sound;
	t_sound			*running_sound;
	t_size			n_weapons;
	t_weapon		**weapons;
}						t_player;

typedef struct			s_level
{
	int				**map;
	t_size			n_walls;
	t_texture		**walls;
	int				ground_color;
	int				ceiling_color;
}						t_level;

typedef struct			s_wolf
{
	SDL_Window		*win_ptr;
	t_size			win_width;
	t_size			win_height;
	t_size			fov;
	t_fbuff			*fb;
	t_bool			loop;
	t_bool			render_textures;
	t_audiodata		*adata;
	t_renderdata	*rdata;
	t_inputdata		*idata;
	t_level			*level;
	t_player		*player;
	t_sprite		*crosshair;
}						t_wolf;

int						w_get_ticks(void);
double					w_degtorad(double var);
int						w_lround(double var);
double					w_dcos(double var);
double					w_dsin(double var);
double					w_dtan(double var);
double					w_dacos(double var);
double					w_dasin(double var);
double					w_abs(double var);
double					w_sq(double var);
t_ivec2					w_ivec2(int x, int y);
t_vec2					w_vec2(double x, double y);
void					w_setvec2(t_vec2 *vec2, double x, double y);
void					w_setivec2(t_ivec2 *ivec2, int x, int y);
t_screenpos				w_init_screenpos(int x_offset, int y_offset,
										t_vec2 stretch, t_byte flags);
t_ivec2					w_get_screenpos(t_screenpos *pos, t_ivec2 sprite_size,
										t_wolf *obj);
t_spriteanimdata		w_spriteanimdata(t_size n_sprites, t_size timecode,
										t_size keycolor);
char					*w_pathcat(char *path, char *file, char *ext);

int						w_multithreaded_render(t_wolf *obj);
void					*w_render_thread(void *arg);
t_size					w_raycasting(double angle, t_dda *d, t_wolf *obj);
void					w_display(t_size column, t_dda *d, int texture_id,
								t_wolf *obj);
void					w_draw_sprite(t_sprite *sprite, t_wolf *obj);
t_bool					w_draw_spriteanim(t_spriteanim *anim, t_wolf *obj);

t_player				*w_newplayer(double x_pos, double y_pos,
									double orientation, t_size n_weapons);
t_texture				*w_newtexture(char *name, int backcolor);
t_sound					*w_newsound(char *name);
t_sprite				*w_newsprite(char *name, t_screenpos pos,
									t_size keycolor, t_wolf *obj);
t_spriteanim			*w_newspriteanim(char *name, t_screenpos pos,
										t_spriteanimdata info, t_wolf *obj);
t_weapon				*w_newweapon(char *name, t_spriteanimdata info,
									t_wolf *obj);

void					w_destroyplayer(t_player **player);
void					w_destroytexture(t_texture **texture);
void					w_destroysound(t_sound **sound);
void					w_destroysprite(t_sprite **sprite);
void					w_destroyspriteanim(t_spriteanim **spriteanim);
void					w_destroyweapon(t_weapon **weapon);
void					w_destroylevel(t_level **level);

void					w_handle_weapon_anim(t_player *p, t_wolf *obj);
void					w_handle_sound(t_wolf *obj);
void					w_handle_input(t_wolf *obj);
void					w_handle_player_movement(double speed_mult,
												t_wolf *obj);
void					w_handle_camera_movement(double speed_multiplier,
												t_wolf *obj);
void					w_handle_player_state(t_player *p, t_inputdata *idata);

t_bool					w_use_weapon(t_player *p);
t_bool					w_reload_weapon(t_player *p);
t_bool					w_play_sound(t_sound *sound);
t_bool					w_stop_sound(t_sound *sound);

int						w_mainscene(t_wolf *obj);

t_size					**w_parse_8b_surface(SDL_Surface *surf);
t_size					**w_parse_24b_surface(SDL_Surface *surf);

t_wolf					*w_init(t_size win_width, t_size win_height,
								t_size fov, char *title);
int						**w_parse_map(const int fd);
int						w_loop(t_wolf *obj);
void					w_deinit(t_wolf **obj);
void					w_fexit(char *error, t_wolf **obj);

#endif
