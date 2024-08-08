/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:38:39 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 09:22:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	redraw_elem(t_text_game *g, t_img img, int x, int y)
{
	int		p[2];
	t_img	images[2];

	p[0] = x;
	p[1] = y;
	images[0] = img;
	images[1] = g->win_img;
	mlx_img_to_img(p, images, 0xFF000000);
}

// void	update_anim(t_text_game *g)
// {
// 	g->tex.n = g->tex.n->next;
// 	if (!g->tex.n)
// 		g->tex.n = g->tex.n_bak;
// 	g->tex.s = g->tex.s->next;
// 	if (!g->tex.s)
// 		g->tex.s = g->tex.s_bak;
// 	g->tex.e = g->tex.e->next;
// 	if (!g->tex.e)
// 		g->tex.e = g->tex.e_bak;
// 	g->tex.w = g->tex.w->next;
// 	if (!g->tex.w)
// 		g->tex.w = g->tex.w_bak;
// }

void	check_move(t_text_game *g)
{
	if (g->pl.keys.left_pressed)
		g->ray.current_angle -= 3;
	if (g->pl.keys.right_pressed)
		g->ray.current_angle += 3;
	if (g->pl.keys.w_pressed)
		move_pl(KEY_W, g, 0, 0);
	if (g->pl.keys.a_pressed)
		move_pl(KEY_A, g, 0, 0);
	if (g->pl.keys.s_pressed)
		move_pl(KEY_S, g, 0, 0);
	if (g->pl.keys.d_pressed)
		move_pl(KEY_D, g, 0, 0);
}

int	cub_update(void *param)
{
	t_text_game	*g;

	g = param;
	if (!(g->frame_count % g->rate))
	{
		// if (!(g->frame_count % (2 * g->rate)))
		// 	update_anim(g);
		if (!(g->frame_count % (10 * g->rate)))
			g->pl.door_cooldown = 0;
		check_move(g);
		cub_minimap(g);
		cub_raycast(g);
		cub_miniview(g);
		redraw_elem(g, *g->scope, WIN_W / 2 - g->scope->width / 2, \
			WIN_H / 2 - g->scope->height / 2);
		redraw_elem(g, g->miniview, WIN_W - g->miniview.width - 20, \
			WIN_H - g->miniview.height - 20);
		if (g->neg == 1)
			cub_invert_color(g);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img.i, 0, 0);
	}
	g->frame_count++;
	return (0);
}
