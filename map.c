/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:31:56 by lchew             #+#    #+#             */
/*   Updated: 2023/02/22 18:40:49 by lchew            ###   ########.fr       */
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
}

void	read_map(int fd, t_map *map)
{
	char	*row;
	int		i;
	int		width_sampling;

	i = 0;
	width_sampling = 0;
	map->coord = ft_calloc(WIN_HEIGHT / IMG_SIZE, sizeof(char *));
	row = get_next_line(fd);
	width_sampling = ft_strlen(row);
	while (row)
	{
		if (i > 34)
			exit_with_error(2, map);
		map->coord[i] = row;
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		if (ft_strlen(row) != width_sampling)
			exit_with_error(3, map);
		++i;
	}
	map->map_width = width_sampling - 1;
	map->map_height = i + 1;
}

void	set_image(t_map *map)
{
	map->wall_img = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_size, &map->img_size);
	map->player_img = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_size, &map->img_size);
	map->chest_img = mlx_xpm_file_to_image(map->mlx, CHEST,
			&map->img_size, &map->img_size);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, EXIT,
			&map->img_size, &map->img_size);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, FLOOR,
			&map->img_size, &map->img_size);
}

int	create_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	set_image(map);
	// printf("player coord: x - %d | y = %d\n", map->chars.player_x, map->chars.player_y);
	while (map->coord[i] != NULL)
	{
		j = 0;
		while (map->coord[i][j] != '\0' && map->coord[i][j] != '\n')
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
	else
		exit_with_error(4, map);
}