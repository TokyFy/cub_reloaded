/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:42:48 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/27 16:11:29 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture(t_texture *texture)
{
	texture->path_no = NULL;
	texture->path_so = NULL;
	texture->path_we = NULL;
	texture->path_ea = NULL;
	texture->cieling = -1;
	texture->floor = -1;
}

void	init_data(t_data *data)
{
	init_texture(&data->texture);
	data->heigth = 0;
	data->width = 0;
	data->map = NULL;
	data->texture.path_ea = NULL;
	data->texture.path_no = NULL;
	data->texture.path_so = NULL;
	data->texture.path_we = NULL;
}

void	init_map(t_list **map, char *line)
{
	if (*map == NULL)
	{
		*map = ft_lstnew(ft_strdup(line));
		(*map)->next = NULL;
	}
	else
	{
		add_the_line(*map, line);
	}
}

int	init_cub(t_cub *cub)
{
	if (!check_map_suround(cub))
		return (0);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGTH, "cub3D");
	cub->buffer = ft_calloc(sizeof(t_mlx_image), 1);
	cub->buffer->img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGTH);
	cub->buffer->width = WIN_WIDTH;
	cub->buffer->heigth = WIN_HEIGTH;
	cub->buffer->addr = mlx_get_data_addr(cub->buffer->img,
			&cub->buffer->bits_per_pixel, &cub->buffer->line_length,
			&cub->buffer->endian);
	return (1);
}

void	init_player(t_cub *cub)
{
	uint	i;
	uint	j;
	char	p;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			p = gme(cub, j, i);
			if (p == '0' || p == '1' || p == ' ')
			{
				j++;
				continue ;
			}
			cub->player->pos_x = j + 0.5;
			cub->player->pos_y = i + 0.5;
			cub->player->direction = chartodeg(p);
			j++;
		}
		i++;
	}
	return ;
}
