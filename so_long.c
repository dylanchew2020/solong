/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:02:12 by lchew             #+#    #+#             */
/*   Updated: 2023/02/07 22:06:00 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#define IMG_SIZE 64

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*relative_path;
	int		img_size;

	relative_path = "./xpm/wall.xpm";
	img_size = IMG_SIZE;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "So Long!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_size, &img_size);
	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// #include <mlx.h>
// #include <stdio.h>

// #define WIDTH 1920
// #define HEIGHT 1080
// #define MAZE_HEIGHT 5
// #define MAZE_WIDTH 13

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_window;
// 	void	*img;
// 	char	*img_data;
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// 	int		i, j;

// 	int maze[MAZE_HEIGHT][MAZE_WIDTH] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 										 {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 										 {1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
// 										 {1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
// 										 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// 	mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Maze");
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);

// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIDTH)
// 		{
// 			if (maze[i / (HEIGHT / MAZE_HEIGHT)][j / (WIDTH / MAZE_WIDTH)] == 1)
// 			{
// 				img_data[i * size_line + j * (bits_per_pixel / 8)] = 0;
// 				img_data[i * size_line + j * (bits_per_pixel / 8) + 1] = 0;
// 				img_data[i * size_line + j * (bits_per_pixel / 8) + 2] = 0;
// 			}
// 			else
// 			{
// 				img_data[i * size_line + j * (bits_per_pixel / 8)] = (char)255;
// 				img_data[i * size_line + j * (bits_per_pixel / 8) + 1] = (char)255;
// 				img_data[i * size_line + j * (bits_per_pixel / 8) + 2] = (char)255;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }


