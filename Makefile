#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:18:15 by rmc-coma          #+#    #+#              #
#    Updated: 2016/05/13 06:40:11 by rmc-coma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ofast
LFLAGS = -lpthread -lm -lc

HDR = 	-I ./libft/include/

LIB =	./libft/libft.a \
		./SDL2/SDL2 \
		./OpenAL/OpenAL

SRC =	main.c \
		w_degtorad.c w_lround.c w_dcos.c w_dsin.c w_dtan.c w_sq.c w_setvec2.c \
		w_setivec2.c w_init.c w_deinit.c w_mainscene.c w_loop.c w_parse_map.c \
		w_newplayer.c w_render_thread.c w_multithreaded_render.c w_newtexture.c \
		w_display.c w_handle_input.c w_handle_player_movement.c w_use_weapon.c \
		w_handle_camera_movement.c w_draw_sprite.c w_newsprite.c w_play_sound.c \
		w_get_ticks.c w_newspriteanim.c w_newweapon.c w_ivec2.c w_newsound.c \
		w_draw_spriteanim.c w_parse_8b_surface.c w_parse_24b_surface.c \
		w_handle_weapon_anim.c w_reload_weapon.c w_stop_sound.c w_vec2.c \
		w_handle_sound.c w_get_screenpos.c w_init_screenpos.c w_raycasting.c \
		w_spriteanimdata.c w_abs.c w_dacos.c w_dasin.c w_pathcat.c w_fexit.c \
		w_destroyplayer.c w_destroysound.c w_destroysprite.c w_destroyweapon.c \
		w_destroyspriteanim.c w_destroytexture.c w_destroylevel.c \
		w_handle_player_state.c


OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(HDR) -c $(SRC)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./libft clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all