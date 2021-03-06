/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 22:29:30 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/05/13 05:00:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_size	w_arrsize(char **array)
{
	t_size	i;

	i = 0;
	while (array[i] != NULL)
		++i;
	return (i);
}

static void		w_initblockstomap(t_size *i, int ***new, t_size nlines)
{
	*new = (int **)malloc(sizeof(int *) * (nlines + 1));
	(*new)[nlines] = NULL;
	*i = 0;
}

static void		w_loopblockstomap(char ***blocks, t_size i, t_size *j,
								int ***new)
{
	while ((*blocks)[*j] != NULL)
	{
		(*new)[i][*j] = ft_atoi((*blocks)[*j]);
		free((*blocks)[*j]);
		++(*j);
	}
}

static int		**w_blockstomap(t_list **blocks_lines, t_size nlines)
{
	int		**new;
	t_list	*to_free;
	t_size	i;
	t_size	j;
	char	**blocks;

	w_initblockstomap(&i, &new, nlines);
	while (i < nlines)
	{
		j = 0;
		blocks = ft_strsplit((char *)((*blocks_lines)->content), ' ');
		new[i] = (int *)malloc(sizeof(int) * (w_arrsize(blocks) + 1));
		w_loopblockstomap(&blocks, i, &j, &new);
		to_free = *blocks_lines;
		*blocks_lines = (*blocks_lines)->next;
		free(to_free->content);
		free(to_free);
		free(blocks);
		new[i][j] = -1;
		i++;
	}
	return (new);
}

int				**w_parse_map(const int fd)
{
	char	*line;
	t_list	*blocks_lines;
	t_size	i;

	line = NULL;
	blocks_lines = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_lstapp(&blocks_lines, ft_lstnew((void *)line, ft_strlen(line)));
		free(line);
		++i;
	}
	close(fd);
	return (w_blockstomap(&blocks_lines, i));
}
