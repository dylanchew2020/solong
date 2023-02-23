/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 15:17:13 by lchew            ###   ########.fr       */
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

//KEYCODES
# define KEY_UP_W 13
# define KEY_DOWN_S 1
# define KEY_LEFT_A 0
# define KEY_RIGHT_D 2
# define KEY_ESC 53

typedef struct s_chars
{
	int	player_x;
	int	player_y;
	int	p_count;
	int	exit_x;
	int	exit_y;
	int	e_count;
	int	collect_x;
	int	collect_y;
	int	c_count;
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
	int		movement_count;
	int		points;
	t_chars	chars;

}	t_map;

// GENERAL FUNCTIONS
void	create_window(t_map *map);
void	free2d(char **array);
void	exit_with_error(int code, t_map *map);

// MAP FUNCTIONS
void	init_map(t_map *map);
void	read_map(int fd, t_map *map);
void	set_image(t_map *map);
int		create_map(t_map *map);
void	chars_init(int i, int j, t_map *map);


// CONTROLLER FUNCTIONS
int		close_window(t_map *map);
int		key_action(int keycode, t_map *map);
void	pos_swap(int x, int y, t_map *map);
void	count_action(t_map *map);

//VALIDATION FUNCTIONS
void	validate_chars(t_map *map);

#endif
