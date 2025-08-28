/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:39:44 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/27 16:02:51 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_struct_map(int i, int curser, char **maps)
{
	int	j;

	j = 0;
	i = 0;
	curser = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'N' || maps[i][j] == 'S' || maps[i][j] == 'E'
				|| maps[i][j] == 'W')
				curser += 1;
			else if (maps[i][j] == '1' || maps[i][j] == '0'
				|| maps[i][j] == ' ')
				curser += 1;
			else
				curser = 0;
			if (curser == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (curser);
}

char	gme(t_cub *cub, uint x, uint y)
{
	if (x > cub->map_width || y > cub->map_height)
	{
		return (' ');
	}
	return (cub->maps[y][x]);
}

int	check_map_suround(t_cub *cub)
{
	uint	i;
	uint	j;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (gme(cub, j, i) == '0')
			{
				if (gme(cub, j, i - 1) == ' ' || gme(cub, j, i + 1) == ' '
					|| gme(cub, j - 1, i) == ' ' || gme(cub, j + 1, i) == ' ')
				{
					ft_error("Not surrounded Maps");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_map(t_cub *cub, char *path)
{
	t_data	*data;
	int		fd;
	int		err;

	data = malloc(sizeof(t_data));
	fd = -1;
	init_data(data);
	if (!map_name(path))
	{
		ft_error("wrong argument _ cub3d map.cub");
		return (free(data), 0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Can't open config file");
		return (perror(path), free(data), 0);
	}
	init_data(data);
	err = get_elements(data, fd);
	if (err)
		bridge(data, cub);
	destroy_data(data);
	free(data);
	return (err);
}
