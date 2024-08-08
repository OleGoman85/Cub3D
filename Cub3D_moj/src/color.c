/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:10:29 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 11:02:27 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int create_trgb(t_color color)
{
    return (color.alpha << 24 | color.red << 16 | color.green << 8 | color.blue);
}

t_color create_rgbt(int color_value)
{
    t_color color;

    color.alpha = (color_value >> 24) & 0xFF;
    color.red = (color_value >> 16) & 0xFF;
    color.green = (color_value >> 8) & 0xFF;
    color.blue = color_value & 0xFF;
    return color;
}

void	get_cf_color(char **dir, t_text_game *g)
{
	char	**fc;
	int		str[2];
	int		c[3];
	t_color	updated_map;

	updated_map.alpha = 0;
	str[0] = !ft_strncmp(dir[0], "F", 2);
	str[1] = !ft_strncmp(dir[0], "C", 2);
	fc = ft_split(dir[1], ',');
	if (!fc || ft_matrixlen(fc) != 3)
	{
		ft_free_matrix(&fc);
		return ;
	}
	c[0] = cub_atoi(fc[0], &updated_map.red);
	c[1] = cub_atoi(fc[1], &updated_map.green);
	c[2] = cub_atoi(fc[2], &updated_map.blue);
	ft_free_matrix(&fc);
	if (c[0] || c[1] || c[2])
		return ;
	if (str[0])
		g->tex.floor = create_trgb(updated_map);
	else if (str[1])
		g->tex.ceiling = create_trgb(updated_map);
}

void	cub_invert_color(t_text_game *g)
{
	int		xy[2];

	xy[1] = -1;
	while (++xy[1] < WIN_H)
	{
		xy[0] = -1;
		while (++xy[0] < WIN_W)
		{
			put_pixel(&g->win_img, xy[0], xy[1], 0xFFFFFF - \
				get_pixel_color(&g->win_img, xy[0], xy[1]));
		}
	}
}

int get_dist_color(int base_color, float distance, int transparency)
{
    t_color color;
    float diff;

    if (distance < 0)
        distance = 0;
    diff = powf(1.14, distance / 7.5);
    color = create_rgbt(base_color);
    if (transparency)
        color.alpha -= (int)diff;
    else
        color.alpha = 256;

    color.red -= (int)diff;
    color.green -= (int)diff;
    color.blue -= (int)diff;
    if (color.alpha < 0)
        color.alpha = 0;
    if (color.red < 0)
        color.red = 0;
    if (color.green < 0)
        color.green = 0;
    if (color.blue < 0)
        color.blue = 0;
    return create_trgb(color);
}

