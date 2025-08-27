/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:50:30 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/27 16:04:54 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_maps(char **maps)
{
	int	i;

	if (!maps)
		return ;
	i = 0;
	while (maps[i])
	{
		free(maps[i]);
		i++;
	}
	free(maps);
}

void	free_map(t_list *map)
{
	t_list	*tmp;

	while (map)
	{
		tmp = map->next;
		free(map->content);
		free(map);
		map = tmp;
	}
}

void	destroy_data(t_data *data)
{
	free(data->texture.path_ea);
	free(data->texture.path_no);
	free(data->texture.path_so);
	free(data->texture.path_we);
	free_maps(data->maps);
}

void	ft_error(const char *error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd((char *)error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	destroy_image(void *mlx, t_mlx_image *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx, img->img);
	free(img);
	return ;
}
