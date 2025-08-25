/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:16:45 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/23 14:21:32 by llalatia         ###   ########.fr       */
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
		return (1);
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

int	check_element(t_data *data)
{
	if (data->texture.path_no == NULL || data->texture.path_no == (char*)-1)
    {
        data->texture.path_no = NULL;
		return (printf("PATH_NO ERROR\n"), 0);
    }
	else if (data->texture.path_so == NULL || data->texture.path_so == (char*)-1)
    {
        data->texture.path_so = NULL;
		return (printf("PATH_SO ERROR\n"), 0);
    }
	else if (data->texture.path_ea == NULL || data->texture.path_ea == (char*)-1)
    {
        data->texture.path_ea = NULL;
		return (printf("PATH_EA ERROR\n") , 0);
    }
	else if (data->texture.path_we == NULL || data->texture.path_we == (char*)-1)
    {
        data->texture.path_we = NULL;
		return (printf("PATH_WE ERROR\n") , 0);
    }
	else if (data->texture.cieling <= -1)
	{
		printf("PATH_CIELING ERROR\n");
		return (0);
	}
	else if (data->texture.floor <= -1)
	{
		printf("PATH_FLOOR ERROR\n");
		return (0);
	}
	return (1);
}
