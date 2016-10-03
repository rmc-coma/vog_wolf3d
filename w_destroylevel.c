/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_destroylevel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 07:40:26 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/03 08:08:32 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_destroylevel(t_level **level)
{
	int	i;

	i = 0;
	if (*level)
	{
		while ((*level)->map[i])
			free((*level)->map[i++]);
		free((*level)->map);
		while ((*level)->n_walls--)
			w_destroytexture(&((*level)->walls[(*level)->n_walls]));
		free((*level)->walls);
		free(*level);
	}
}
