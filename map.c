/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:31:56 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 18:02:31 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->mlx = NULL;
	map->window = NULL;
	map->wall_img = NULL;
	map->player_img = NULL;
	map->chest_img = NULL;
	map->exit_img = NULL;
	map->floor_img = NULL;
	map->path = NULL;
	map->img_size = IMG_SIZE;
	map->fd = 0;
	map->coord = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->movement_count = 0;
	map->points = 0;
}

void	read_map(int fd, t_map *map)
{
	char	*row;
	char	*gnl;
	int		i;
	int		width_sampling;

	i = 0;
	width_sampling = 0;
	map->coord = ft_calloc(WIN_HEIGHT / IMG_SIZE, sizeof(char *));
	if (!map->coord)
		exit_with_error(2, map);
	gnl = get_next_line(fd);
	row = ft_strtrim(gnl, "\n");
	if (ft_strlen(row) > WIN_WIDTH / IMG_SIZE)
		exit_with_error(7, map);
	width_sampling = ft_strlen(row);
	while (row)
	{
		if (i == WIN_HEIGHT / IMG_SIZE)
			exit_with_error(7, map);
		map->coord[i] = row;
		free(gnl);
		gnl = get_next_line(fd);
		row = ft_strtrim(gnl, "\n");
		if (row == NULL)
			break ;
		if (ft_strlen(row) != width_sampling)
			exit_with_error(3, map);
		++i;
	}
	free(gnl);
	map->map_width = width_sampling;
	map->map_height = i + 1;
}

int	create_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	set_image(map);
	while (map->coord[i] != NULL)
	{
		j = 0;
		while (map->coord[i][j] != '\0')
		{
			if (map->coord[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->window,
					map->wall_img, j * 32, i * 32);
			else if (map->coord[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->window,
					map->floor_img, j * 32, i * 32);
			else
				chars_init(i, j, map);
			++j;
		}
		++i;
	}
	return (0);
}

void	chars_init(int i, int j, t_map *map)
{
	if (map->coord[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->window,
			map->player_img, j * 32, i * 32);
		map->chars.player_x = j;
		map->chars.player_y = i;
	}
	else if (map->coord[i][j] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->window,
			map->chest_img, j * 32, i * 32);
		map->chars.collect_x = j;
		map->chars.collect_y = i;
	}
	else if (map->coord[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->window,
			map->exit_img, j * 32, i * 32);
		map->chars.exit_x = j;
		map->chars.exit_y = i;
	}
}
