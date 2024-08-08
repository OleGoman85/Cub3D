/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:56:23 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 11:00:03 by ogoman           ###   ########.fr       */
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
void put_pixel(t_img *img, int x, int y, int color);

/* Retrieves color as int at given position from an image */
unsigned int get_pixel_color(t_img *img, int x, int y);

/* Draws a section of a screen in a certain color */
void draw_rectangle(t_img *img, t_vector position, t_vector dimensions, int color);

/* Loads XPM image and fills t_img struct for it */
t_img *load_img(void *ptr, char *path);

/* Writes first img to second image to given pos, ignoring "c1" pixels */
void mlx_img_to_img(int p[2], t_img img[2], int c1);

#endif
