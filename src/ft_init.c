/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:38:37 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/19 14:05:35 by franaivo         ###   ########.fr       */
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

void	init_elmt(t_data *data, char **str)
{
	int	i;

	i = 0;
	if (ft_compare("NO", str[0]))
	{
		if (data->texture.path_no)
			return ;
		data->texture.path_no = ft_strdup(str[1]);
	}
	else if (ft_compare("SO", str[0]))
	{
		if (data->texture.path_so)
			return ;
		data->texture.path_so = ft_strdup(str[1]);
	}
	else if (ft_compare("WE", str[0]))
	{
		if (data->texture.path_we)
			return ;
		data->texture.path_we = ft_strdup(str[1]);
	}
	else if (ft_compare("EA", str[0]))
	{
		if (data->texture.path_ea)
			return ;
		data->texture.path_ea = ft_strdup(str[1]);
	}
	else if (ft_compare("F", str[0]))
	{
		i = get_rgb(str[1], 0, 0, 0);
		if (data->texture.floor != -1)
			return ;
		data->texture.floor = i;
	}
	else if (ft_compare("C", str[0]))
	{
		i = get_rgb(str[1], 0, 0, 0);
		if (data->texture.cieling != -1)
			return ;
		data->texture.cieling = i;
	}
	else
	{
		printf("erreur de donnee des element\n");
		return ;
	}
}
