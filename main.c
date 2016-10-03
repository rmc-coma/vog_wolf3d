/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 00:15:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 00:54:05 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_wolf	*obj;

	obj = w_init(WINDOW_WIDTH, WINDOW_HEIGHT, 60, "Wolf3D");
	w_mainscene(obj);
	w_deinit(&obj);
	return (0);
}
