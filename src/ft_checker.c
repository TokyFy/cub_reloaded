/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:42:05 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/23 12:42:29 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_first_last_line(t_data *data)
{
	int	j;

	j = 0;
	while (data->maps[0][j])
	{
		if (data->maps[0][j] != '1' && data->maps[0][j] != ' ')
		{
			printf("first\n");
			return (0);
		}
		j++;
	}
	j = 0;
	while (data->maps[data->heigth - 1][j])
	{
		if (data->maps[data->heigth - 1][j] != '1' && data->maps[data->heigth
			- 1][j] != ' ')
		{
			printf("last\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_right_left_wall(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] == ' ')
			j++;
		if (array[i][j] != '1' || array[i][ft_strlen(array[i]) - 1] != '1')
		{
			printf("rigth_left = %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_on_lines(char *new_maps)
{
	int	j;

	j = 0;
	while (new_maps[j] && new_maps[j + 1])
	{
		if (new_maps[j] == ' ' && new_maps[j + 1] == '0')
			return (printf("ito"), 0);
		else if (new_maps[j] == '0' && new_maps[j + 1] == ' ')
			return (0);
		else if (new_maps[j] == ' ' && (new_maps[j + 1] == 'N'
				|| new_maps[j + 1] == 'S' || new_maps[j + 1] == 'E'
				|| new_maps[j + 1] == 'W'))
			return (0);
		else if ((new_maps[j] == 'N' || new_maps[j] == 'S' || new_maps[j] == 'E'
				|| new_maps[j] == 'W') && new_maps[j + 1] == ' ')
			return (0);
		j++;
	}
	if ((new_maps[j] == '0' || new_maps[j] == 'N' || new_maps[j] == 'S'
			|| new_maps[j] == 'W' || new_maps[j] == 'E')
		&& new_maps[j + 1] == '\0')
		return (0);
	return (1);
}

int	check_on_col(char *new_map, char *new_maps)
{
	int	j;

	j = 0;
	while (new_map[j] && new_maps[j])
	{
		if (new_map[j] == ' ' && new_maps[j] == '0')
			return (0);
		else if (new_map[j] == '0' && new_maps[j] == ' ')
			return (0);
		else if ((new_map[j] == 'N' || new_map[j] == 'S' || new_map[j] == 'E'
				|| new_map[j] == 'W') && new_maps[j] == ' ')
			return (0);
		else if (new_map[j] == ' ' && (new_maps[j] == 'N' || new_maps[j] == 'S'
				|| new_maps[j] == 'E' || new_map[j] == 'W'))
			return (0);
		j++;
	}
	return (1);
}

int	check_zero_position(char **new_maps)
{
	int	i;

	i = 0;
	while (new_maps[i])
	{
		if (check_on_lines(new_maps[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (new_maps[i] && new_maps[i + 1])
	{
		if (check_on_col(new_maps[i], new_maps[i + 1]) == 0)
			return (0);
		i++;
	}
	return (1);
}
