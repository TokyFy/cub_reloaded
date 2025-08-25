/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:50:30 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/23 13:50:39 by llalatia         ###   ########.fr       */
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
	free_maps(data->maps);
}
