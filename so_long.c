/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:12 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 15:56:01 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	init_map(&map);
	if (argc != 2)
		exit_with_error(0, &map);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		exit_with_error(1, &map);
	read_map(map.fd, &map);
	validate_chars(&map);
	while (map.coord[i] != NULL)
		printf("%s\n", map.coord[i++]);
	printf("width %i, height %i\n", map.map_width, map.map_height);
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
		write(1, "Incorrect Input Parameter.\n", 28);
	else if (code == 1)
		write(1, "File Error!\n", 13);
	else if (code == 2)
		write(1, "Map Size Exceeded Limit!\n", 26);
	else if (code == 3)
		write(1, "Map Not Rectangular!\n", 22);
	else if (code == 4)
		write(1, "Map Contains Prohibited Characters!\n", 37);
	else if (code == 5)
		write(1, "Missing Mandatory Characters\n", 30);
	else if (code == 6)
		write(1, "Map Not Enclosed!\n", 19);
	else if (code == 7)
		write(1, "You Win!!!\n", 12);
	else if (code == 8)
		write(1, "You Win!!!\n", 12);
	else if (code == 9)
		write(1, "You Win!!!\n", 12);
	else if (code == 99)
		write(1, "Gracefully Exited.\n", 20);
	if (code > 1)
		free2d(map->coord);
	exit(0);
}

