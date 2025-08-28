/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:38:37 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/27 16:06:08 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ptr_error(void **ptr)
{
	if (*ptr == (void *)-1)
		return ;
	free(*ptr);
	*ptr = (void *)-1;
}

static void	init_texture_path(t_data *data, char **str)
{
	char	**path;

	path = NULL;
	if (ft_compare("NO", str[0]))
		path = &data->texture.path_no;
	else if (ft_compare("SO", str[0]))
		path = &data->texture.path_so;
	else if (ft_compare("WE", str[0]))
		path = &data->texture.path_we;
	else if (ft_compare("EA", str[0]))
		path = &data->texture.path_ea;
	else
		return (ft_error("Unknown map element"));
	if (*path)
		return (ptr_error((void *)path));
	*path = ft_strdup(str[1]);
}

static void	init_texture_color(t_data *data, char **str)
{
	int	i;

	if (ft_compare("F", str[0]))
	{
		i = get_rgb(str[1], 0, 0, 0);
		if (data->texture.floor != -1)
			return ((void)(data->texture.floor = -2));
		data->texture.floor = i;
	}
	else if (ft_compare("C", str[0]))
	{
		i = get_rgb(str[1], 0, 0, 0);
		if (data->texture.cieling != -1)
			return ((void)(data->texture.cieling = -2));
		data->texture.cieling = i;
	}
	else
		ft_error("Unknown map element");
}

void	init_elmt(t_data *data, char **str)
{
	if (!str || !str[0] || !str[1])
		return ;
	if (ft_compare("NO", str[0]) || ft_compare("SO", str[0]) || ft_compare("WE",
			str[0]) || ft_compare("EA", str[0]))
		init_texture_path(data, str);
	else if (ft_compare("F", str[0]) || ft_compare("C", str[0]))
		init_texture_color(data, str);
	else
		ft_error("Unknown map element");
}

int	load(t_cub *cub)
{
	int	i;

	cub->texture[0] = load_texture(cub, cub->textures[0]);
	cub->texture[1] = load_texture(cub, cub->textures[1]);
	cub->texture[2] = load_texture(cub, cub->textures[2]);
	cub->texture[3] = load_texture(cub, cub->textures[3]);
	i = 0;
	if (cub->texture[0] == NULL || cub->texture[1] == NULL
		|| cub->texture[2] == NULL || cub->texture[3] == NULL)
	{
		ft_error("Non xpm file found");
		while (i < 4)
		{
			destroy_image(cub->mlx, cub->texture[i]);
			cub->texture[i] = NULL;
			i++;
		}
		destroy_image(cub->mlx, cub->buffer);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		return (0);
	}
	return (1);
}
