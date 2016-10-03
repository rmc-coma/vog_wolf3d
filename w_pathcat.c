/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_pathcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 10:29:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/02 10:31:40 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*w_pathcat(char *path, char *filename, char *ext)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(path, filename);
	str = ft_strjoin(tmp, ext);
	free(tmp);
	return (str);
}
