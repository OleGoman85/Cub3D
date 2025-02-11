/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:35 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/11 09:13:35 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/cub3d.h"

/**
 * Adds an image to the animation list and manages image count.
 * 
 * Decrements the animation counter if the image and pointers are valid. If the image is NULL, 
 * the function frees the image and sets a flag indicating no more images. Otherwise, it adds 
 * the image to the animation list and returns the updated list.
 * 
 * @param img Pointer to the image structure.
 * @param anim Pointer to the pointer of the animation list.
 * @param n Pointer to an array of two integers used for managing image count and flags.
 * 
 * @return The updated animation list.
 */

t_list *get_anim(t_img *img, t_list **anim, int (*n)[2])
{
    // Если указатели действительны и изображение не NULL
    if (n && anim && *anim && img)
    {
        // Уменьшаем счетчик
        (*n)[0]--;
    }

    // Если изображение NULL, просто возвращаем текущий список анимаций
    if (!img)
    {
        return *anim;
    }

    // Если изображение не инициализировано
    if (!img->i)
    {
        free(img);
        // Устанавливаем флаг, что изображений больше нет
        (*n)[1] = 0;
        return *anim;
    }

    // Добавляем изображение в список анимаций
    ft_lstadd_back(anim, ft_lstnew(img));
    return *anim;
}

/**
 * Processes texture definitions and assigns them to the game structure.
 * 
 * Splits the input string into components, identifies the texture type (e.g., NO, SO, EA, WE),
 * and loads the corresponding image. If a color definition is detected, it processes the color. 
 * If the definition is invalid, it reports an error.
 * 
 * @param trim The trimmed line containing texture or color definitions.
 * @param g Pointer to the game structure to store the texture or color information.
 * @param n Pointer to an array of two integers used for managing texture count and flags.
 */

void	check_textures(char *trim, t_text_game *g, int (*n)[2])
{
	char	**dir;

	dir = ft_split(trim, ' ');
	if (!dir)
	{
		free(trim);
		handle_error(ERR_OUT_OF_MEMORY, g, NULL, 1);
	}
	if (!ft_strncmp(dir[0], "NO", 3))
        g->tex.n = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.n, n);
		// g->tex.n_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.n, n);
	else if (!ft_strncmp(dir[0], "SO", 3))
		g->tex.s = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.s, n);
        // g->tex.s_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.s, n);
	else if (!ft_strncmp(dir[0], "EA", 3))
		g->tex.e = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.e, n);
        // g->tex.e_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.e, n);
	else if (!ft_strncmp(dir[0], "WE", 3))
		// g->tex.w_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.w, n);
        g->tex.w = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.w, n);
	else if ((!ft_strncmp(dir[0], "F", 2) && g->tex.floor == -1)
            || (!ft_strncmp(dir[0], "C", 2) && g->tex.ceiling == -1))
		get_cf_color(dir, g);
	else
	{
		ft_free_matrix(&dir);
		handle_error(ERR_INV_MAP, g, NULL, 1);
	}
	ft_free_matrix(&dir);
}

/**
 * Reads a map file and populates the game structure with texture and map data.
 * 
 * Opens the specified map file and reads it line by line. The function distinguishes between 
 * texture definitions and map data, updates the map and texture information, and handles errors 
 * for missing or invalid textures and empty files.
 * 
 * @param file The path to the map file.
 * @param g Pointer to the game structure to be populated with map and texture data.
 */

void	read_map(char *file, t_text_game *g)
{
	char	*line[2];
	int		n[2];

	n[0] = -1; //  для подсчета строк карты
	n[1] = -1; // для отслеживания текстур
	g->fd = open(file, O_RDONLY);
	handle_error(ERR_INV_FILE, g, file, g->fd < 0);
	while (1)
	{
		line[0] = get_next_line(g->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n"); //udaljaet simvol \n s nachalo i konca stroki
		free(line[0]);
		if (line[1] && line[1][0] && ++n[0] < 6)
			check_textures(line[1], g, &n);
		else if ((line[1] && line[1][0]) || n[0] >= 6)
			g->map = ft_extend_matrix(g->map, line[1]);
		if ((int)ft_strlen(line[1]) > g->width)
			g->width = ft_strlen(line[1]);
		free(line[1]);
	}
	handle_error(ERR_EMPTY_FILE, g, NULL, !n[0]); //если не было прочитано ни одной строки карты
	handle_error(ERR_INV_TEX, g, NULL, !n[1]); // не было найдено ни одной текстуры
	g->height = ft_matrixlen(g->map); // Высота карты
}


/**
 * Validates the walls of the map at the specified row and column boundaries.
 * 
 * Checks if the map boundaries are correctly defined with walls ('1') and ensures that the 
 * boundaries of the map are properly set for both the top/bottom rows and middle rows.
 * 
 * @param g Pointer to the game structure containing the map data.
 * @param row The row index being checked.
 * @param col_start The starting column index of the row, after trimming spaces.
 * @param col_end The ending column index of the row, after trimming spaces.
 */

static void validate_walls(t_text_game *g, int row, int col_start, int col_end)
{
    if (row == 0 || row == g->height - 1)
    {
        if (col_end - col_start + 1 < 3 || 
            g->map[row][col_start] != '1' || 
            g->map[row][col_end] != '1')
        {
            handle_error(ERR_INV_WALL, g, NULL, 1);
        }
    }
    else
    {
        if (col_end > col_start &&
            (g->map[row][col_start] != '1' || 
             g->map[row][col_end] != '1'))
        {
            handle_error(ERR_INV_WALL, g, NULL, 1);
        }
    }
}
/**
 * Validates the entire map for correct boundaries and checks for required elements.
 * 
 * Iterates through each row of the map, trims spaces, and validates wall boundaries. Ensures 
 * that the map contains all necessary elements and checks for the presence of at least one row.
 * 
 * @param g Pointer to the game structure containing the map data.
 */
void check_map(t_text_game *g)
{
    int row;
    int col_start, col_end;

    row = 0;
    while (row < g->height)
    {
        trim_spaces(g->map[row], &col_start, &col_end);

        // Проверка на пустую строку
        if (col_start > col_end)
            handle_error(ERR_INV_MAP, g, NULL, 1);

        validate_walls(g, row, col_start, col_end);

        row++;
    }

    // Проверка на наличие всех элементов карты
    check_elements(g);

    // Проверка на количество строк
    handle_error(ERR_INV_MAP, g, NULL, g->height == 0);
}
















////////////////////////





/*
#include "../inc/cub3d.h"

t_list *get_anim(t_img *img, t_list **anim, int (*n)[2])
{
    if (n && anim && *anim && img)
        (*n)[0]--;
    if (!img)
        return (*anim);
    if (!img->i)
    {
        free(img);
        (*n)[1] = 0;
        return (*anim);
    }
    ft_lstadd_back(anim, ft_lstnew(img));
    return (*anim);
}


void check_textures(char *trim, t_text_game *g, int (*n)[2])
{
    char    **dir;

    dir = ft_split(trim, ' ');
    if (!dir)
    {
        free(trim);
        handle_error(ERR_OUT_OF_MEMORY, g, NULL, 1);
    }
    if (!ft_strncmp(dir[0], "NO", 3))
        g->tex.n_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.n, n);
    else if (!ft_strncmp(dir[0], "SO", 3))
        g->tex.s_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.s, n);
    else if (!ft_strncmp(dir[0], "EA", 3))
        g->tex.e_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.e, n);
    else if (!ft_strncmp(dir[0], "WE", 3))
        g->tex.w_bak = get_anim(load_img(g->mlx_ptr, dir[1]), &g->tex.w, n);
    else if ((!ft_strncmp(dir[0], "F", 2) && g->tex.floor == -1) || \
        (!ft_strncmp(dir[0], "C", 2) && g->tex.ceiling == -1))
        get_cf_color(dir, g);
    else
    {
        ft_free_matrix(&dir);
        handle_error(ERR_INV_MAP, g, NULL, 1);
    }
    ft_free_matrix(&dir);
}



void read_map(char *file, t_text_game *g)
{
    char    *line[2];
    int     n[2];

    n[0] = -1; //  для подсчета строк карты
    n[1] = -1; // для отслеживания текстур
    g->fd = open(file, O_RDONLY);
    handle_error(ERR_INV_FILE, g, file, g->fd < 0);
    while (1)
    {
        line[0] = get_next_line(g->fd);
        if (!line[0])
            break;
        line[1] = ft_strtrim(line[0], "\n"); // удаляет символ \n с начала и конца строки
        free(line[0]);
        if (line[1] && line[1][0] && ++n[0] < 6)
            check_textures(line[1], g, &n); // Передаем &n, так как check_textures ожидает int (*)[2]
        else if ((line[1] && line[1][0]) || n[0] >= 6)
            g->map = ft_extend_matrix(g->map, line[1]);
        if ((int)ft_strlen(line[1]) > g->width)
            g->width = ft_strlen(line[1]);
        free(line[1]);
    }
    handle_error(ERR_EMPTY_FILE, g, NULL, !n[0]); // если не было прочитано ни одной строки карты
    handle_error(ERR_INV_TEX, g, NULL, !n[1]); // не было найдено ни одной текстуры
    g->height = ft_matrixlen(g->map); // Высота карты
}


void check_map(t_text_game *g)
{
    int j;
    int i;
    int w;

    j = -1;
    while (++j < g->height)
    {
        w = ft_strlen(g->map[j]) - 1;
        i = 0;

        // Удаление пробелов с начала строки
        while (g->map[j][i] == ' ' && i <= w)
            i++;
        // Удаление пробелов с конца строки
        while (g->map[j][w] == ' ' && w > 0)
            w--;

        if (ft_strncmp(g->map[j], "", 1) == 0)
            handle_error(ERR_INV_MAP, g, NULL, 1);

        if ((j == 0 || j == g->height - 1) && ft_strlen(g->map[j]) - (w - i + 1) - ft_countchar(g->map[j], '1'))
            handle_error(ERR_INV_WALL, g, NULL, 1);
        else if (w > i && (g->map[j][i] != '1' || g->map[j][w] != '1'))
            handle_error(ERR_INV_WALL, g, NULL, 1);
    }
    check_elements(g);
    handle_error(ERR_INV_MAP, g, NULL, !j);
}

*/