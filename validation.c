/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 19:42:03 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate(t_map *map)
{
	int		i;
	int		j;
	char	**tmp_map;

	i = 0;
	tmp_map = ft_calloc(map_height, sizeof(char *));
	while (map->coord[i] != NULL)
	{
		j = 0;
		tmp_map[i] = map->coord[i];
		while (map->coord[i][j] != '\0')
		{
			if (validate_init(i, j, map) != 1)
				exit_with_error(4, map);
			++j;
		}
		++i;
	}
	validate_chars(map);
	validate_wall(i - 1, j - 1, map);
	validate_path(tmp_map, map);
}

int	validate_init(int i, int j, t_map *map)
{
	int	valid_char;

	valid_char = 0;
	if (map->coord[i][j] == 'P')
	{
		++map->chars.p_count;
		valid_char = 1;
	}
	else if (map->coord[i][j] == 'E')
	{
		++map->chars.e_count;
		valid_char = 1;
	}
	else if (map->coord[i][j] == 'C')
	{
		++map->chars.c_count;
		valid_char = 1;
	}
	else if (map->coord[i][j] == '1' || map->coord[i][j] == '0')
		valid_char = 1;
	return (valid_char);
}

void	validate_chars(t_map *map)
{
	if (map->chars.p_count != 1 || map->chars.e_count != 1)
		exit_with_error(5, map);
	if (map->chars.c_count < 1)
		exit_with_error(5, map);
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

void	validate_path(char **tmp_map, t_map *map)
{
	validate_path(tmp_map, map);
}

int	check_directions(int i, int j, char **tmp_map)
{
	int	empty;
	int	exit;

	empty = 0;
	exit = 0;
	if (tmp_map[i][j] == '0' || tmp[i][j] == 'C')

}
