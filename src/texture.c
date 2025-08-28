/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:47 by franaivo          #+#    #+#             */
/*   Updated: 2025/04/16 08:26:36 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_mlx_image	*load_texture(t_cub *cub, char *path)
{
	t_mlx_image	*texture_n;

	texture_n = malloc(sizeof(t_mlx_image));
	texture_n->img = mlx_xpm_file_to_image(cub->mlx, path, &texture_n->width,
			&texture_n->heigth);
	if (texture_n->img == NULL)
	{
		free(texture_n);
		return (NULL);
	}
	texture_n->addr = mlx_get_data_addr(texture_n->img,
			&texture_n->bits_per_pixel, &texture_n->line_length,
			&texture_n->endian);
	return (texture_n);
}

void	normalize_maps(t_cub *cub)
{
	uint	i;
	uint	j;
	char	*new;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		new = ft_calloc(cub->map_width + 1, sizeof(char));
		j = 0;
		while (cub->maps[i][j])
		{
			new[j] = cub->maps[i][j];
			j++;
		}
		while (j < cub->map_width)
		{
			new[j] = ' ';
			j++;
		}
		free(cub->maps[i]);
		cub->maps[i] = new;
		i++;
	}
}
