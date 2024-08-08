/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:16:35 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 09:52:00 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

float	distance_to_door(t_text_game *g, float ray_current_angle, float *x, float *y)
{
	float	d;
	float	ray_cos;
	float	ray_sin;

	ray_cos = cos(degree_to_radians(ray_current_angle)) / g->ray.precision;
	ray_sin = sin(degree_to_radians(ray_current_angle)) / g->ray.precision;
	*x = g->pl.position_x + 0.5;
	*y = g->pl.position_y + 0.5;
	while (!ft_strchr("1oc", g->map[(int)*y][(int)*x]) && \
		sqrt(powf(*x - g->pl.position_x - 0.5, 2.) + \
		powf(*y - g->pl.position_y - 0.5, 2.)) < g->ray.max_distance)
	{
		*x += ray_cos;
		*y += ray_sin;
	}
	d = sqrt(powf(*x - g->pl.position_x - 0.5, 2.) + powf(*y - g->pl.position_y - 0.5, 2.));
	d = d * cos(degree_to_radians(ray_current_angle - g->ray.current_angle));
	return (d);
}

void	move_pl(int k, t_text_game *g, float ray_cos, float ray_sin)
{
	float	current_angle;

	current_angle = g->ray.current_angle;
	if (k == KEY_A)
		current_angle = g->ray.current_angle - 90;
	else if (k == KEY_S)
		current_angle = g->ray.current_angle - 180;
	else if (k == KEY_D)
		current_angle = g->ray.current_angle + 90;
	ray_cos = cos(degree_to_radians(current_angle)) * g->pl.speed;
	ray_sin = sin(degree_to_radians(current_angle)) * g->pl.speed;
	if (!ft_strchr("1c", g->map[(int)(g->pl.position_y + 0.5 + \
			(3 * ray_sin))][(int)(g->pl.position_x + 0.5)]))
		g->pl.position_y += ray_sin;
	if (!ft_strchr("1c", \
		g->map[(int)(g->pl.position_y + 0.5)][(int)(g->pl.position_x + 0.5 + (3 * ray_cos))]))
		g->pl.position_x += ray_cos;
}

void	action_door(t_text_game *g)
{
	float	d;
	float	x;
	float	y;

	if (g->pl.door_cooldown || \
			ft_strchr("oc", g->map[(int)(g->pl.position_y + 0.5)][(int)(g->pl.position_x + 0.5)]))
		return ;
	d = distance_to_door(g, g->ray.current_angle, &x, &y);
	if (d < g->ray.max_distance && g->map[(int)y][(int)x] == 'c')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'o';
		// mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_g.i, 0, 0);
	}
	else if (d < g->ray.max_distance && g->map[(int)y][(int)x] == 'o')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'c';
		// mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_r.i, 0, 0);
	}
}
