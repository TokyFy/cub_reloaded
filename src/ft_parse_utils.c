/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:57:57 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/27 16:11:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_info(t_data *data, char *tmp)
{
	int		i;
	char	**split;

	if (check_map_or_elt(tmp) || data->map != NULL)
	{
		init_map(&data->map, tmp);
		if (data->width < (int)ft_strlen(tmp))
			data->width = ft_strlen(tmp);
	}
	else
	{
		i = 0;
		split = ft_split(tmp, ' ');
		if (split == NULL)
			return ;
		if (split[0] == NULL)
			return ((void)(free(split)));
		while (split[i] != NULL)
			i++;
		if (i > 2)
			return ((void)(free_maps(split)));
		init_elmt(data, split);
		free_maps(split);
	}
}

int	parse_map_data(t_data *data)
{
	char	**newmaps;

	newmaps = new_maps(data);
	free_maps(data->maps);
	data->maps = newmaps;
	if ((check_first_last_line(data) == 0))
	{
		ft_error("Map or Player error");
		return (0);
	}
	else if (check_struct_map(0, 0, newmaps) == 0 || check_player(newmaps) != 1)
	{
		ft_error("Map or Player error");
		return (0);
	}
	else if (check_zero_position(newmaps) == 0)
	{
		ft_error("Map or Player error");
		return (0);
	}
	return (1);
}

int	get_elements(t_data *data, int fd)
{
	char	*line;
	char	*tmp;
	int		max_line;

	max_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		max_line++;
		tmp = remove_jumpline(line);
		free(line);
		parse_info(data, tmp);
		free(tmp);
		if (max_line >= 64)
			break ;
		line = get_next_line(fd);
	}
	data->heigth = ft_lstsize(data->map);
	data->maps = lst_to_str(data->map);
	free_map(data->map);
	data->map = NULL;
	if (check_element(data) == 0 || parse_map_data(data) == 0)
		return (0);
	return (1);
}

static void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i])
			free(cub->textures[i]);
		i++;
	}
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->player)
		free(cub->player);
	if (cub->maps)
		free_strs(cub->maps);
	free_textures(cub);
}
