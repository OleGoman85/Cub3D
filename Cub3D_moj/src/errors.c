/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:36 by ogoman            #+#    #+#             */
/*   Updated: 2024/07/30 10:00:14 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	cub_perror(t_cub_err err, t_game *g, char *param, int c)
{
	if (!c)
		return (0);
	cub_end(g);
	write(2, "cub3d: ", 7 * (err != end)); //  умножение на 0 или 1 позволяет контролировать вывод 
	write(2, "invalid number of arguments\n", 28 * (err == inv_ac));
	write(2, "cub3D not run in root of the project\n", 37 * (err == inv_pwd));
	write(2, "file must be of .cub type\n", 26 * (err == inv_ext));
	write(2, "error opening file: ", 20 * (err == inv_file));
	write(2, "file is empty\n", 14 * (err == empty_file));
	write(2, "devide out of memory\n", 21 * (err == no_memory));
	write(2, "invalid color\n", 15 * (err == inv_color));
	write(2, "map not surrounded by walls\n", 28 * (err == inv_wall));
	write(2, "invalid map\n", 12 * (err == inv_map));
	write(2, "invalid character\n", 18 * (err == inv_charac));
	write(2, "invalid texture file\n", 21 * (err == inv_tex));
	write(2, "invalid number of players\n", 26 * (err == inv_player));
	ft_putendl_fd(param, 2);
	if (err == inv_ac && ft_putchar_fd('\n', 2))
		cub_usage(1);
	if (err == end)
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
	cub_perror(end, param, NULL, 1);
	return (0);
}