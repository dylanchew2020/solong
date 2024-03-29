/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:08:30 by lchew             #+#    #+#             */
/*   Updated: 2023/02/26 12:00:51 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_chars(t_map *map)
{
	map->chars.player_x = 0;
	map->chars.player_y = 0;
	map->chars.p_cnt = 0;
	map->chars.vp_x = 0;
	map->chars.vp_y = 0;
	map->chars.exit_x = 0;
	map->chars.exit_y = 0;
	map->chars.e_cnt = 0;
	map->chars.collect_x = 0;
	map->chars.collect_y = 0;
	map->chars.c_cnt = 0;
}

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

	ori_pos = &map->coord[map->chars.player_y][map->chars.player_x];
	new_pos = &map->coord[map->chars.player_y + y][map->chars.player_x + x];
	if (*new_pos == '0')
	{
		tmp = *ori_pos;
		*ori_pos = *new_pos;
		*new_pos = tmp;
	}
	else if (*new_pos == 'C')
	{
		*new_pos = *ori_pos;
		*ori_pos = '0';
		--map->chars.c_cnt;
		map->points += 100;
	}
	else if (*new_pos == '1' || (*new_pos == 'E' && map->chars.c_cnt != 0))
		write(1, "WALL!\n", 7);
	else if (*new_pos == 'E' && map->chars.c_cnt == 0)
		exit_with_error(9, map);
	count_action(map);
}

void	count_action(t_map *map)
{
	char	*count;
	char	*point;

	++map->movement_count;
	count = ft_itoa_base(map->movement_count, BASE_DEC, BASE_DEC_C);
	point = ft_itoa_base(map->points, BASE_DEC, BASE_DEC_C);
	write(1, "Total Action: ", 14);
	write(1, count, ft_strlen(count));
	write(1, " | Total Points: ", 17);
	write(1, point, ft_strlen(point));
	write(1, "\n", 2);
}
