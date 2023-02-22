/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:08:30 by lchew             #+#    #+#             */
/*   Updated: 2023/02/22 18:59:40 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->window);
	exit_with_error(99, map);
	return (0);
}

int	key_action(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_window(map);
	else if (keycode == KEY_UP_W)
		pos_swap(0, -1, map);
	else if (keycode == KEY_DOWN_S)
		pos_swap(0, 1, map);
	else if (keycode == KEY_LEFT_A)
		pos_swap(-1, 0, map);	
	else if (keycode == KEY_RIGHT_D)
		pos_swap(1, 0, map);
	return (0);
}

void	pos_swap(int x, int y, t_map *map)
{
	char	*ori_pos;
	char	*new_pos;
	char	tmp;

	*ori_pos = map->coord[map->chars.player_y][map->chars.player_x];
	*new_pos = map->coord[map->chars.player_y + y][map->chars.player_x + x];
	if (*new_pos != '1')
	{
		tmp = *ori_pos;
		*ori_pos = *new_pos;
		*new_pos = tmp;
	}
	else
		write(1, "WALL!\n", 7);
}
