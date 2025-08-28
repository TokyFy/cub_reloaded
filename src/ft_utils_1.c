/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:51:52 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/27 15:55:29 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**lst_to_str(t_list *map)
{
	int		i;
	int		j;
	t_list	*head_map;
	char	**mymap;

	i = 0;
	j = ft_lstsize(map);
	head_map = map;
	mymap = malloc(sizeof(char *) * (j + 1));
	if (!mymap)
		return (NULL);
	while (i < j)
	{
		mymap[i] = ft_strdup(head_map->content);
		head_map = head_map->next;
		i++;
	}
	mymap[i] = NULL;
	return (mymap);
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	reset_cub(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->buffer = NULL;
	cub->maps = NULL;
	cub->player = NULL;
	cub->texture[0] = NULL;
	cub->texture[1] = NULL;
	cub->texture[2] = NULL;
	cub->texture[3] = NULL;
	cub->textures[0] = NULL;
	cub->textures[1] = NULL;
	cub->textures[2] = NULL;
	cub->textures[3] = NULL;
}

void	bridge(t_data *data, t_cub *cub)
{
	cub->ceil_color = data->texture.cieling;
	cub->floor_color = data->texture.floor;
	cub->textures[0] = ft_strdup(data->texture.path_no);
	cub->textures[1] = ft_strdup(data->texture.path_so);
	cub->textures[2] = ft_strdup(data->texture.path_we);
	cub->textures[3] = ft_strdup(data->texture.path_ea);
	cub->map_height = data->heigth;
	cub->map_width = data->width;
	cub->maps = data->maps;
	data->maps = NULL;
	cub->player = malloc(sizeof(t_player));
	cub->player->direction = 0;
	cub->player->pos_x = 1.5;
	cub->player->pos_y = 1.5;
}

int	chartodeg(char dir)
{
	if (dir == 'W')
		return (180);
	if (dir == 'S')
		return (90);
	if (dir == 'N')
		return (270);
	if (dir == 'E')
		return (0);
	return (0);
}
