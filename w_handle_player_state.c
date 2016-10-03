/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handle_player_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 06:38:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 06:58:01 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_handle_player_state(t_player *p, t_inputdata *idata)
{
	if ((!idata->m_for && !idata->m_bac && !idata->m_sleft && !idata->m_sright)
		|| (idata->m_for && idata->m_bac)
		|| (idata->m_sleft && idata->m_sright))
	{
		p->is_walking = FALSE;
		p->is_running = FALSE;
	}
	else if (idata->m_for && idata->shift)
	{
		p->is_running = TRUE;
		p->is_walking = FALSE;
	}
	else if (idata->m_for || idata->m_bac || idata->m_sleft || idata->m_sright)
	{
		p->is_running = FALSE;
		p->is_walking = TRUE;
	}
}
