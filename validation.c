/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:37 by lchew             #+#    #+#             */
/*   Updated: 2023/02/23 15:31:31 by lchew            ###   ########.fr       */
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
		while (map->coord[i][j] != '\0' && map->coord[i][j] != '\n')
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
}
