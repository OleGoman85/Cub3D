/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:36 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 11:59:00 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	cub_perror(t_cub_err err, t_text_game *g, char *param, int c)
{
	if (!c)
		return (0);
	// cub_end(g);
	(void)g;
	write(2, "cub3d: ", 7 * (err != ERR_END)); //  умножение на 0 или 1 позволяет контролировать вывод 
	write(2, "invalid number of arguments\n", 28 * (err == ERR_INV_AC));
	write(2, "cub3D not run in root of the project\n", 37 * (err == ERR_INV_PATH));
	write(2, "file must be of .cub type\n", 26 * (err == ERR_INV_EXT));
	write(2, "error opening file: ", 20 * (err == ERR_INV_FILE));
	write(2, "file is empty\n", 14 * (err == ERR_EMPTY_FILE));
	write(2, "devide out of memory\n", 21 * (err == ERR_OUT_OF_MEMORY));
	write(2, "invalid color\n", 15 * (err == ERR_INV_COLOR));
	write(2, "map not surrounded by walls\n", 28 * (err == ERR_INV_WALL));
	write(2, "invalid map\n", 12 * (err == ERR_INV_MAP));
	write(2, "invalid character\n", 18 * (err == ERR_INV_CHARAC));
	write(2, "invalid texture file\n", 21 * (err == ERR_INV_TEX));
	write(2, "invalid number of players\n", 26 * (err == ERR_INV_PLAYER));
	ft_putendl_fd(param, 2);
	// if (err == ERR_INV_AC && ft_putchar_fd('\n', 2))
	// 	cub_usage(1);
	if (err == ERR_END)
		exit(0);
	exit(1);
	return (1);
}

void	cub_usage(int errno)
{
	ft_putstr_fd("Cub3D\nA simple raycaster with MinilibX\n\n", 2);
	ft_putstr_fd("usage: cub3d <map_file.cub>\n", 2);
	exit(errno);
}

int	cub_exit(void *param)
{
	cub_perror(ERR_END, param, NULL, 1);
	return (0);
}

// void	cub_usage(int errno)
// {
// 	ft_putstr_fd("Cub3D\nA simple raycaster with MinilibX\n\n", 2);
// 	ft_putstr_fd("usage: cub3d <map_file.cub>\n", 2);
// 	exit(errno);
// }

// int	cub_exit(void *param)
// {
// 	cub_perror(end, param, NULL, 1);
// 	return (0);
// }