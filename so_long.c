/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:12 by lchew             #+#    #+#             */
/*   Updated: 2023/02/22 16:57:15 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_chars	chars;
	int		i;
	int		win_width;
	int		win_height;

	i = 0;
	init_map(&map);
	// printf("argc: %i\n", argc);
	if (argc != 2)
		exit_with_error(0, &map);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		exit_with_error(1, &map);
	read_map(map.fd, &map);
	while (map.coord[i] != NULL)
		printf("%s\n", map.coord[i++]);
	printf("width %i, height %i\n", map.map_width, map.map_height);
	win_width = map.map_width * 32;
	win_height = map.map_height * 32;
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, win_width, win_height, "So Long!");
	mlx_loop_hook(map.mlx, create_map, &map);
	mlx_key_hook(map.window, close_window, &map);
	mlx_key_hook(map.window, move_char, &map);
	mlx_loop(map.mlx);

	//1920x1088 - 60x34 - 32x32pixels
	/* init_map(&map);
	map.path = "./resources/wall32x32.xpm";
	map.img_size = 32;

	map.mlx = mlx_init();
	map.mlx_window = mlx_new_window(map.mlx, 1920, 1080, "So Long!");
	map.wall_img = mlx_xpm_file_to_image(map.mlx, map.path, &map.img_size, &map.img_size);
	mlx_put_image_to_window(map.mlx, map.mlx_window, map.wall_img, 0, 0);
	mlx_loop(map.mlx); */
	return (0);
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
		write(1, "Incorrect Input parameter.\n", 28);
	else if (code == 1)
		write(1, "File Error!\n", 13);
	else if (code == 2)
		write(1, "Map Size Exceeded Limit!\n", 26);
	else if (code == 3)
		write(1, "Incorrect Map Size!\n", 21);
	else if (code == 99)
		write(1, "Gracefully Exited.\n", 20);
	if (code > 1)
		free2d(map->coord);
	exit(0);
}

