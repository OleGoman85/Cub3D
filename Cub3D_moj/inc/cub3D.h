/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:40:40 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 10:59:42 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "keycodes.h"
# include <mlx.h>
# include "get_next_line.h"
# include "game_mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# ifndef WIN_H
#  define WIN_H 480
# endif

# ifndef WIN_W
#  define WIN_W 640
# endif

# ifndef SIZE
#  define SIZE 7
# endif

/* Перечисление для обработки различных сообщений об ошибках */
typedef enum e_cub_err
{
    ERR_END,          // Конец программы
    ERR_INV_AC,       // Неверный доступ
    ERR_INV_EXT,      // Неверное расширение файла
    ERR_INV_FILE,     // Неверный файл
    ERR_EMPTY_FILE,   // Пустой файл
    ERR_OUT_OF_MEMORY,    // Нет памяти
    ERR_INV_COLOR,    // Неверный цвет
    ERR_INV_WALL,     // Неверная стена
    ERR_INV_MAP,      // Неверная карта
    ERR_INV_CHARAC,   // Неверный символ
    ERR_INV_PLAYER,   // Неверный игрок
    ERR_INV_TEX,      // Неверная текстура
    ERR_INV_PATH       // Неверный путь
} t_cub_err;

/* Структура для хранения цветов с прозрачностью */
typedef struct s_color
{
    long alpha; // Прозрачность
    long red; // Красный цвет
    long green; // Зеленый цвет
    long blue; // Синий цвет
} t_color;

/* Структура для хранения текстур стен, пола и потолка */
typedef struct s_tex
{
    t_list *n;       // Список текстур для северной стены
    t_list *s;       // Список текстур для южной стены
    t_list *w;       // Список текстур для западной стены
    t_list *e;       // Список текстур для восточной стены
    t_img *b;        // Текстура для пола или потолка
    int floor;       // Цвет пола в формате RGB (например, 0xRRGGBB)
    int ceiling;     // Цвет потолка в формате RGB
} t_tex;

/* Структура для хранения состояний клавиш */
typedef struct s_key
{
    int w_pressed;      // Клавиша W нажата
    int a_pressed;      // Клавиша A нажата
    int s_pressed;      // Клавиша S нажата
    int d_pressed;      // Клавиша D нажата
    int left_pressed;   // Клавиша влево нажата
    int right_pressed;  // Клавиша вправо нажата
} t_key;

/* Структура для хранения атрибутов игрока */
typedef struct s_player
{
    float position_x;    // Позиция игрока по оси X
    float position_y;    // Позиция игрока по оси Y
    char dir;           // Направление игрока
    float speed;        // Скорость игрока
    int door_cooldown;  // Таймер для взаимодействия с дверями
    t_key keys;         // Состояние клавиш игрока
} t_player;

/* Структура для хранения данных по лучам */
typedef struct s_ray
{
    float angle_increment; // Угол между лучами
    float current_angle;       // Текущий угол луча
    float cos;         // Косинус угла луча
    float sin;         // Синус угла луча
    float hfov;        // Горизонтальное поле зрения
    float max_distance;         // Предел расстояния для лучей
    int precision;     // Точность расчета лучей
} t_ray;

/* Структура для хранения состояния игры */
typedef struct s_text_game
{
    int fd;             // Дескриптор файла карты
    char **map;         // Двумерный массив карты
    int height;        // Высота карты
    int width;         // Ширина карты
    int mouse_x;       // X-координата мыши
    int rate;          // Частота обновления
    int neg;           // Флаг инверсии цветов
    long frame_count;      // Количество кадров
    void *mlx_ptr;     // Указатель на MiniLibX
    void *win_ptr;     // Указатель на окно
    t_img win_img;     // Изображение окна

    t_img minimap;     // Миникарта
    t_img miniview;    // Мини-вид
    t_img *scope;      // Целевой прицел
    t_tex tex;         // Текстуры для игры
    t_ray ray;         // Данные для лучей
    t_player pl;       // Игрок
    float x;           // Координата X (не используется в коде)
    float y;           // Координата Y (не используется в коде)
} t_text_game;




/* Check possible map errors */
void	check_map(t_text_game *g);

/* Reads file with gnl */
void	read_map(char *file, t_text_game *g);

/* Retrieves next line from a given fd */
char	*get_next_line(int fd);

/* Prints appropriate error message and exits, freeing everything */
int		cub_perror(t_cub_err err, t_text_game *g, char *param, int c);

/* Prints usage for the cub3D program */
void	cub_usage(int errno);

/* Function called by mlx when exiting */
int		cub_exit(void *param);

/* Atoi for colors (more restrictive than original) */
int		cub_atoi(const char *nptr, long *nbr);

/* Fills color int for floor and ceiling */
void	get_cf_color(char **dir, t_text_game *g);

/* Drecreases RGB value of color as object gets further */
int		get_dist_color(int color, float ds, int tr);

/* Frees all necessary things before exiting */
void	cub_end(t_text_game *g);

/* Initializes game */
void	game_init(t_text_game *g);

/* Draws game */
// void	drawt_text_game(t_text_game *g);

/* Initialize raycast data */
void	init_ray(t_text_game *g);

/* Converts degrees to radians */
float	degree_to_radians(float degree);

/* Draws a 2D minimap */
void	cub_minimap(t_text_game *g);

/* Draws a section of the 2D minimap */
void	cub_miniview(t_text_game *g);

/* Function to shoot rays in a given direction to find walls */
void	cub_raycast(t_text_game *g);

/* Function called inside mlx loop */
int		cub_update(void *param);

/* Checks if there're c's in position range [n0,n1] of m */
int		checkcn(char *m, char c, int n0, int n1);

/* Check every element of the map: spaces + characters */
void	check_elements(t_text_game *g);

/* Draws 3D view on window-sized image */
void	cub_draw(t_text_game *g, int ray_count, float dis);

/* Checks which wall has been hit to choose proper texture */
t_img	*get_texture(t_text_game *g);

/* Moves player depending on which key was pressed */
void	move_pl(int k, t_text_game *g, float ray_cos, float ray_sin);

/* Checks player surroundings to open/close doors */
void	action_door(t_text_game *g);

/* Inverts color of window-sized image */
void	cub_invert_color(t_text_game *g);

/* Adds spaces to end of all lines to ensure all lines have the same width */
char	**alight_map_rows(t_text_game *g);

#endif
