/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroyplayer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 00:45:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/12 01:11:28 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroyplayer(t_player **player)
{
	if (*player)
	{
		w_destroysound(&((*player)->walking_sound));
		w_destroysound(&((*player)->running_sound));
		while ((*player)->n_weapons)
			w_destroyweapon(&((*player)->weapons[--(*player)->n_weapons]));
		free(*player);
	}
}
