/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:08:30 by lchew             #+#    #+#             */
/*   Updated: 2023/02/22 16:51:43 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_window(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->window);
		exit_with_error(99, map);
	}
	return (0);
}

int	move_char(int keycode, t_map *map)
{
	if (keycode == 13)
		printf("W\n");
	return (0);
}