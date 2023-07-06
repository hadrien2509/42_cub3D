/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:08:31 by samy              #+#    #+#             */
/*   Updated: 2023/07/05 20:30:58 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_pos(int x, int y, t_pos *pos)
{
	pos->x = x;
	pos->y = y;
}

t_rect	*set_rect(t_pos *pos, t_pos *end_pos, t_rect *rect)
{
	rect->pos = pos;
	rect->end_pos = end_pos;
	return (rect);
}

void	draw_rect(t_rect *r, t_pos *max_p, int color, t_game *g)
{
	int		i;
	int		j;
	t_pos	max;
	t_pos	tmp;

	set_pos(MINI_SQUARE_SIZE, MINI_SQUARE_SIZE, &tmp);
	if (!r->end_pos)
		r->end_pos = &tmp;
	if (!max_p)
		set_pos(WIN_W, WIN_H, &max);
	else
		max = *max_p;
	i = 0;
	while (i < r->end_pos->y && r->pos->y + i < max.y)
	{
		j = 0;
		while (j < r->end_pos->x && r->pos->x + j < max.x)
		{
			mlx_pixel_put(g->mlx, g->window, r->pos->x + j, r->pos->y + i,
				color);
			j++;
		}
		i++;
	}
}
