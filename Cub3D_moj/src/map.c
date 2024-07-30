/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:34:27 by ogoman            #+#    #+#             */
/*   Updated: 2024/07/30 12:14:10 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    read_map(char *file, t_game *g)
{
    char    *line[2];
    int     n[2];

	n[0] = -1; //  для подсчета строк карты
	n[1] = -1; // для отслеживания текстур
    g->fd = open(file, O_RDONLY);
    cub_perror(inv_file, g, file, g->fd < 0);
    while (1)
    {
        line[0] = get_next_line(g->fd);
        if(!line[0])
            break ;
		line[1] = ft_strtrim(line[0], "\n"); // Удаляет символ \n с начала и конца строки
        free(line[0]);
        if(line[1] && line[1][0] && ++n[0] < 6)
            check_textures(line[1], g, &n);
        else if ((line[1] && line[1][0] || n[0] >= 6))
            g->map = ft_extend_matrix(g->map, line[1]);
        if((int)ft_strlen(line[1]) > g->width)
            g->width = ft_strlen(line[1]);
        free(line[1]);
    }
	cub_perror(empty_file, g, NULL, !n[0]); //если не было прочитано ни одной строки карты
	cub_perror(inv_tex, g, NULL, !n[1]); // не было найдено ни одной текстуры
	g->height = ft_matrixlen(g->map); // Высота карты
}