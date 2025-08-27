/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:16:45 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/27 15:06:00 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_name(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i < 5)
		return (0);
	if (av[i - 4] == '.' && av[i - 3] == 'c' && av[i - 2] == 'u' && av[i
			- 1] == 'b')
	{
		if (av[i - 5] == '/')
			return (0);
		return (1);
	}
	return (0);
}

int	check_map_or_elt(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

int	check_player(char **maps)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'N' || maps[i][j] == 'S' || maps[i][j] == 'E'
				|| maps[i][j] == 'W')
			{
				count += 1;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	check_color_element(t_data *data)
{
	if (data->texture.cieling <= -1)
	{
		ft_error("Invalid cieling color");
		return (0);
	}
	if (data->texture.floor <= -1)
	{
		ft_error("Invalid floor color");
		return (0);
	}
	return (1);
}

int	check_element(t_data *data)
{
	if (data->texture.path_no == NULL || data->texture.path_no == (char *)-1)
	{
		data->texture.path_no = NULL;
		return (ft_error("Texture NO not found"), 0);
	}
	else if (data->texture.path_so == NULL
		|| data->texture.path_so == (char *)-1)
	{
		data->texture.path_so = NULL;
		return (ft_error("Texture SO not found"), 0);
	}
	else if (data->texture.path_ea == NULL
		|| data->texture.path_ea == (char *)-1)
	{
		data->texture.path_ea = NULL;
		return (ft_error("Texture EA not found"), 0);
	}
	else if (data->texture.path_we == NULL
		|| data->texture.path_we == (char *)-1)
	{
		data->texture.path_we = NULL;
		return (ft_error("Texture WE not found"), 0);
	}
	return (check_color_element(data));
}
