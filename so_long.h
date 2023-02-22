/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/22 16:57:39 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <stdio.h>

# define IMG_SIZE 32
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1088
# define WALL "./resources/wall32x32.xpm"
# define PLAYER "./resources/pacman32x32.xpm"
# define CHEST "./resources/cherry32x32.xpm"
# define EXIT "./resources/exit32x32.xpm"
# define FLOOR "./resources/floor32x32.xpm"

typedef struct s_chars
{
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
	int	collect_x;
	int	collect_y;
}	t_chars;

typedef struct s_map
{
	void	*mlx;
	void	*window;
	void	*wall_img;
	void	*player_img;
	void	*chest_img;
	void	*exit_img;
	void	*floor_img;
	char	*path;
	int		img_size;
	int		fd;
	char	**coord;
	int		map_width;
	int		map_height;
	t_chars	chars;

}	t_map;

//GENERAL FUNCTIONS
void	free2d(char **array);
void	exit_with_error(int code, t_map *map);

//MAP FUNCTIONS
void	init_map(t_map *map);
void	read_map(int fd, t_map *map);
void	set_image(t_map *map);
int		create_map(t_map *map);
int		close_window(int keycode, t_map *map);

//CONTROLLER FUNCTIONS
int		move_char(int keycode, t_map *map);

#endif
