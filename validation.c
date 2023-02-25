/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/25 16:32:59 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->tmp = ft_calloc(map->map_height + 1, sizeof(char *));
	if (!map->tmp)
		exit_with_error(2, map);
	while (map->coord[i] != NULL)
	{
		j = 0;
		map->tmp[i] = ft_strdup(map->coord[i]);
		while (map->coord[i][j] != '\0')
		{
			if (validate_init(i, j, map) != 1)
				exit_with_error(4, map);
			++j;
		}
		++i;
	}
	if (map->chars.p_cnt != 1 || map->chars.e_cnt != 1 || map->chars.c_cnt < 1)
		exit_with_error(5, map);
	validate_wall(i - 1, j - 1, map);
	validate_path(map);
	free2d(map->tmp);
}

int	validate_init(int i, int j, t_map *map)
{
	int	valid_char;

	valid_char = 0;
	if (map->coord[i][j] == 'P')
	{
		map->chars.vp_x = j;
		map->chars.vp_y = i;
		++map->chars.p_cnt;
		valid_char = 1;
	}
	else if (map->coord[i][j] == 'E')
	{
		++map->chars.e_cnt;
		valid_char = 1;
	}
	else if (map->coord[i][j] == 'C')
	{
		++map->chars.c_cnt;
		valid_char = 1;
	}
	else if (map->coord[i][j] == '1' || map->coord[i][j] == '0')
		valid_char = 1;
	return (valid_char);
}

void	validate_wall(int y, int x, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j <= x)
	{
		if (map->coord[0][j] != '1')
			exit_with_error(6, map);
		if (map->coord[y][j] != '1')
			exit_with_error(6, map);
		++j;
	}
	while (i <= y - 1)
	{
		if (map->coord[i][0] != '1')
			exit_with_error(6, map);
		if (map->coord[i][x] != '1')
			exit_with_error(6, map);
		++i;
	}
}

void	validate_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	collapse(map->chars.vp_y, map->chars.vp_x, map);
	while (map->tmp[i] != NULL)
	{
		j = 0;
		while (map->tmp[i][j] != '\0')
		{
			if (map->tmp[i][j] == 'E' || map->tmp[i][j] == 'C')
				exit_with_error(8, map);
			++j;
		}
		++i;
	}
}

void	collapse(int i, int j, t_map *map)
{
	if (map->tmp[i][j] != '1' && map->tmp[i][j] != 'H')
	{
		map->tmp[i][j] = 'H';
		collapse(i, j + 1, map);
		collapse(i + 1, j, map);
		collapse(i, j - 1, map);
		collapse(i - 1, j, map);
	}
}
