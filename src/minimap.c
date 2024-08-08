/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:14:50 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 08:54:42 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

void	cub_miniview(t_text_game *g)
{
	int	xy[2];
	int	updated_map[2];

	updated_map[1] = -1;
	xy[1] = (g->pl.position_y + 0.5) * SIZE - (int)(g->miniview.height / 2);
	while (++updated_map[1] < (g->miniview.height))
	{
		updated_map[0] = -1;
		xy[0] = (g->pl.position_x + 0.5) * SIZE - (int)(g->miniview.width / 2);
		while (++updated_map[0] < g->miniview.width)
		{
			if (xy[1] >= 0 && xy[1] < (g->height * SIZE) && xy[0] >= 0 \
						&& xy[0] < (g->width * SIZE))
				put_pixel(&g->miniview, updated_map[0], updated_map[1], \
					get_pixel_color(&g->minimap, xy[0], xy[1]));
			else
				put_pixel(&g->miniview, updated_map[0], updated_map[1], 0xFF000000);
			xy[0]++;
		}
		xy[1]++;
	}
}

int	get_mini_color(t_text_game *g, int len, int xy[2])
{
	int	color;

	color = 0xFF000000;
	if (xy[0] < len && g->map[xy[1]][xy[0]] == ' ')
		color = 0xFF000000;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] == 'c')
		color = 0x00FF0000;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] == 'o')
		color = 0x0000FF00;
	else if (xy[0] < len && g->map[xy[1]][xy[0]] != '1')
		color = 0x005E5C64;
	else if (xy[0] < len)
		color = 0x008BB5F8;
	return (color);
}

void	cub_minimap(t_text_game *g)
{
	int	xy[2];
	int	len;

	xy[1] = -1;
	while (++xy[1] < g->height)
	{
		xy[0] = -1;
		len = ft_strlen(g->map[xy[1]]);
		while (++xy[0] < g->width)
			draw_rectcurrent_angle(&g->minimap, \
				ft_newvector(xy[0] * SIZE, xy[1] * SIZE), \
				ft_newvector(SIZE, SIZE), get_mini_color(g, len, xy));
	}
}
