/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 02:50:27 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/04/01 02:50:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	w_dsin(double var)
{
	return (sin(var * M_PI / 180.0));
}