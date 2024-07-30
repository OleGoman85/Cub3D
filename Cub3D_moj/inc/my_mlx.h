/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:56:23 by ogoman            #+#    #+#             */
/*   Updated: 2024/07/16 11:50:03 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H

#define MY_MLX_H

#include "../libft/libft.h"

typedef struct s_img
{
	int height;	  // Высота изображения
	int width;	  // Ширина изображения
	void *i;	  // Указатель на изображение (обычно для MiniLibX)
	char *addr;	  // Указатель на адрес данных изображения (для доступа к пикселям)
	int bpp;	  // Количество бит на пиксель (bits per pixel)
	int line_len; // Длина строки изображения в байтах
	int endian;	  // Порядок байтов (endianness) изображения
} t_img;

/* Sets color for a pixel at a position in an image */
void my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* Retrieves color as int at given position from an image */
unsigned int my_mlx_pixel_get(t_img *data, int x, int y);

/* Draws a section of a screen in a certain color */
void my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c);

/* Loads XPM image and fills t_img struct for it */
t_img *mlx_load_img(void *ptr, char *path);

/* Writes first img to second image to given pos, ignoring "c1" pixels */
void mlx_img_to_img(int p[2], t_img img[2], int c1);

/* Draws a vertical line: width = i, height = [j[0],j[1]) */
void mlx_draw_vline(t_img img, int i, int j[2], int color);

#endif
