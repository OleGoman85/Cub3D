/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:38:32 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 09:19:50 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_ray(t_text_game *g)
{
	g->ray.current_angle = 0;
	if (g->pl.dir == 'S')
		g->ray.current_angle = 90;
	else if (g->pl.dir == 'W')
		g->ray.current_angle = 180;
	else if (g->pl.dir == 'N')
		g->ray.current_angle = 270;
	g->ray.hfov = 30;
	g->ray.angle_increment = 2 * g->ray.hfov / WIN_W;
	g->ray.precision = 50;
	g->ray.max_distance = 11;
}

float	distance_to_wall(t_text_game *g, float ray_angle)
{
	float	d;

	g->ray.cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	g->ray.sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	g->x = g->pl.position_x + 0.5;
	g->y = g->pl.position_y + 0.5;
	while (!ft_strchr("1c", g->map[(int)g->y][(int)g->x]) && \
		sqrt(powf(g->x - g->pl.position_x - 0.5, 2.) + \
		powf(g->y - g->pl.position_y - 0.5, 2.)) < g->ray.max_distance)
	{
		g->x += g->ray.cos;
		g->y += g->ray.sin;
		if (ft_strchr("1c", g->map[(int)g->y][(int)g->x]))
			put_pixel(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00FF0000);
		else if (ray_angle - 1 < g->ray.current_angle && ray_angle + 1 > g->ray.current_angle)
			put_pixel(&g->minimap, g->x * SIZE, g->y * SIZE, 0x0000FF00);
		else
			put_pixel(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00BDC1C6);
	}
	draw_rectcurrent_angle(&g->minimap, ft_newvector((int)(g->pl.position_x + 0.5) * SIZE, \
		(int)(g->pl.position_y + 0.5) * SIZE), ft_newvector(SIZE, SIZE), 0x00FDD663);
	d = sqrt(powf(g->x - g->pl.position_x - 0.5, 2.) + powf(g->y - g->pl.position_y - 0.5, 2.));
	return (d * cos(degree_to_radians(ray_angle - g->ray.current_angle)));
}

void	cub_raycast(t_text_game *g)
{
	float	ray_angle;
	int		ray_count;
	float	dist;

	ray_angle = g->ray.current_angle - g->ray.hfov;
	ray_count = -1;
	while (++ray_count < WIN_W)
	{
		dist = distance_to_wall(g, ray_angle);
		cub_draw(g, ray_count, dist);
		ray_angle += g->ray.angle_increment;
	}
}
