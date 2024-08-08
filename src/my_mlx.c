/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:16:12 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 08:54:42 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void put_pixel(t_img *img, int x, int y, int color)
{
    char *pixel_location;

    pixel_location = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)pixel_location = color;
}

unsigned int get_pixel_color(t_img *img, int x, int y)
{
    char *pixel_location;

    pixel_location = img->addr + (y * img->line_len + x * (img->bpp / 8));
    return *(unsigned int *)pixel_location;
}

void draw_rectcurrent_angle(t_img *img, t_vector position, t_vector dimensions, int color)
{
    int x;
    int y;

    y = 0;
    while (y < dimensions.y)
    {
        x = 0;
        while (x < dimensions.x)
        {
            put_pixel(img, position.x + x, position.y + y, color);
            x++;
        }
        y++;
    }
}

void mlx_img_to_img(int p[2], t_img img[2], int c1)
{
    int xy[2];
    int color;

    xy[1] = 0;
    while (xy[1] < img[0].height)
    {
        xy[0] = 0;
        while (xy[0] < img[0].width)
        {
            if (xy[0] + p[0] >= 0 && xy[1] + p[1] >= 0)
            {
                color = get_pixel_color(&img[0], xy[0], xy[1]);
                if (color != c1)
                {
                    put_pixel(&img[1], xy[0] + p[0], xy[1] + p[1], color);
                }
            }
            xy[0]++;
        }
        xy[1]++;
    }
}

/**
 * Checks if the file path is valid.
 * 
 * @param file_path The path to the file.
 * @return 1 if the path is valid, otherwise 0.
 */
static int is_valid_image_path(const char *file_path)
{
    return file_path && ft_strrncmp(file_path, ".xpm", 4) == 0;
}

/**
 * Creates a t_img structure and checks if memory allocation was successful.
 * 
 * @return A pointer to the t_img structure or NULL if memory allocation failed.
 */
static t_img *create_image_structure(void)
{
    t_img *image = malloc(sizeof(t_img));
    if (!image) {
        return NULL;
    }
    image->i = NULL;
    return image;
}

/**
 * Loads an image from a file and initializes the t_img structure.
 * 
 * @param mlx_ptr Pointer to the MLX (MiniLibX) instance.
 * @param file_path Path to the image file.
 * @param image Pointer to the t_img structure to initialize.
 * @return 1 if the image was successfully loaded, otherwise 0.
 */
static int load_image_from_file(void *mlx_ptr, char *file_path, t_img *image)
{
    image->i = mlx_xpm_file_to_image(mlx_ptr, file_path, &image->width, &image->height);
    if (!image->i) {
        return 0;
    }
    image->addr = mlx_get_data_addr(image->i, &image->bpp, &image->line_len, &image->endian);
    return 1;
}

/**
 * Loads an image from a file and creates a t_img structure.
 * 
 * @param mlx_ptr Pointer to the MLX (MiniLibX) instance used to load the image.
 * @param file_path Path to the image file (must be .xpm).
 * @return A pointer to a t_img structure containing the image data, or NULL if the image could not be loaded.
 */
t_img *load_img(void *mlx_ptr, char *file_path)
{
    int file_descriptor;
    t_img *image;

    if (!is_valid_image_path(file_path))
        return NULL;
    file_descriptor = open(file_path, O_RDONLY);
    if (file_descriptor < 0)
        return NULL;
    close(file_descriptor);
    image = create_image_structure();
    if (!image)
        return NULL;
    if (!load_image_from_file(mlx_ptr, file_path, image))
	{
        free(image);
        return NULL;
    }

    return image;
}
