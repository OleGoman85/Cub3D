/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:35:56 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/11 09:19:32 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_animation(t_text_game *g, t_list *start)
{
	t_list	*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (g && ((t_img *)temp->content)->i)
			mlx_destroy_image(g->mlx_ptr, ((t_img *)temp->content)->i);
		free(temp->content);
		free(temp);
	}
}

void	destroy_images(t_text_game *g)
{
	free_animation(g, g->tex.n);
	// free_animation(g, g->tex.n_bak);
	free_animation(g, g->tex.s);
	// free_animation(g, g->tex.s_bak);
	free_animation(g, g->tex.e);
	// free_animation(g, g->tex.e_bak);
	free_animation(g, g->tex.w);
	// free_animation(g, g->tex.w_bak);
	if (g->tex.b && g->tex.b->i)
		mlx_destroy_image(g->mlx_ptr, g->tex.b->i);
	if (g->win_img.i)
		mlx_destroy_image(g->mlx_ptr, g->win_img.i);
	// if (g->win_g.i)
	// 	mlx_destroy_image(g->mlx_ptr, g->win_g.i);
	// if (g->win_r.i)
	// 	mlx_destroy_image(g->mlx_ptr, g->win_r.i);
	if (g->scope && g->scope->i)
		mlx_destroy_image(g->mlx_ptr, g->scope->i);
	if (g->win_ptr)
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	if (g->minimap.i)
		mlx_destroy_image(g->mlx_ptr, g->minimap.i);
	if (g->miniview.i)
		mlx_destroy_image(g->mlx_ptr, g->miniview.i);
	free(g->tex.b);
	free(g->scope);
}

void	cleanup_game(t_text_game *g)
{
	if (!g)
		return ;
	ft_free_matrix(&g->map);
	if (g->fd > 0)
		close(g->fd);
	destroy_images(g);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
}
