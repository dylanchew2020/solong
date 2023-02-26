/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:12 by lchew             #+#    #+#             */
/*   Updated: 2023/02/25 17:02:03 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	init_map(&map);
	init_chars(&map);
	if (argc != 2)
		exit_with_error(0, &map);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		exit_with_error(1, &map);
	read_map(map.fd, &map);
	validate(&map);
	create_window(&map);
	return (0);
}

void	create_window(t_map *map)
{
	int		win_width;
	int		win_height;

	win_width = map->map_width * 32;
	win_height = map->map_height * 32;
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, win_width, win_height, "So Long!");
	mlx_hook(map->window, 17, 0, close_window, map);
	mlx_key_hook(map->window, key_action, map);
	mlx_loop_hook(map->mlx, create_map, map);
	mlx_loop(map->mlx);
}

void	free2d(char **array)
{
	char	**temp;

	temp = array;
	while (temp != NULL && *temp != NULL)
	{
		free(*temp);
		++temp;
	}
	free(array);
}

void	exit_with_error(int code, t_map *map)
{
	if (code == 0)
		write(1, "Error\nIncorrect Input Parameter.\n", 34);
	else if (code == 1)
		write(1, "Error\nFile Error!\n", 19);
	else if (code == 2)
		write(1, "Error\nMemory Allocation Failed\n", 32);
	else if (code == 3)
		write(1, "Error\nMap Not Rectangular!\n", 28);
	else if (code == 4)
		write(1, "Error\nMap Contains Prohibited Characters!\n", 43);
	else if (code == 5)
		write(1, "Error\nInvalid No. of Characters\n", 33);
	else if (code == 6)
		write(1, "Error\nMap Not Enclosed!\n", 25);
	else if (code == 7)
		write(1, "Error\nMap Size Exceeded Limit!\n", 32);
	else if (code == 8)
		write(1, "Error\nNo Valid Path to Collectible or Exit\n", 44);
	else if (code == 9)
		write(1, "You Win!!!\n", 12);
	else if (code == 99)
		write(1, "Gracefully Exited.\n", 20);
	if (code > 2)
		free2d(map->coord);
	exit(0);
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
