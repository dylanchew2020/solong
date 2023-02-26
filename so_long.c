/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:12 by lchew             #+#    #+#             */
/*   Updated: 2023/02/26 12:32:45 by lchew            ###   ########.fr       */
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
		write(1, "\e[1;31mError\nIncorrect Input Parameter.\e[0m\n", 45);
	else if (code == 1)
		write(1, "\e[1;31mError\nFile Error!\e[0m\n", 30);
	else if (code == 2)
		write(1, "\e[1;31mError\nMemory Allocation Failed.\e[0m\n", 44);
	else if (code == 3)
		write(1, "\e[1;31mError\nMap Not Rectangular!\e[0m\n", 39);
	else if (code == 4)
		write(1, "\e[1;31mError\nMap Contains Prohibited Characters!\e[0m\n", 54);
	else if (code == 5)
		write(1, "\e[1;31mError\nInvalid No. of Characters!\e[0m\n", 45);
	else if (code == 6)
		write(1, "\e[1;31mError\nMap Not Enclosed!\e[0m\n", 36);
	else if (code == 7)
		write(1, "\e[1;31mError\nMap Size Exceeded Limit! Max: 60x34\e[0m\n", 54);
	else if (code == 8)
		write(1, "\e[1;31mError\nNo Valid Path to Collectible or Exit\e[0m\n", 55);
	else if (code == 9)
		write(1, "\e[1;32mYou Win!!!\e[0m\n", 23);
	else if (code == 99)
		write(1, "\e[1;33mGracefully Exited.\e[0m\n", 31);
	if (code > 2)
		free2d(map->coord);
	exit(0);
}
