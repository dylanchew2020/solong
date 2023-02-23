/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 17:13:48 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_chars(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->coord[i] != NULL)
	{
		j = 0;
		while (map->coord[i][j] != '\0')
		{
			if (map->coord[i][j] == 'P')
				++map->chars.p_count;
			else if (map->coord[i][j] == 'E')
				++map->chars.e_count;
			else if (map->coord[i][j] == 'C')
				++map->chars.c_count;
			++j;
		}
		++i;
	}
	if (map->chars.p_count != 1 || map->chars.e_count != 1)
		exit_with_error(5, map);
	if (map->chars.c_count < 1)
		exit_with_error(5, map);
	validate_wall(i - 1, j - 1, map);
}

void	validate_wall(int x, int y, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j <= y)
	{
		if (map->coord[0][j] != '1')
			exit_with_error(6, map);
		if (map->coord[x][j] != '1')
			exit_with_error(6, map);
		++j;
	}
	while (i <= x - 1)
	{
		if (map->coord[i][0] != '1')
			exit_with_error(6, map);
		if (map->coord[i][y] != '1')
			exit_with_error(6, map);
		++i;
	}
}
