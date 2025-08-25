/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_another_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:39:44 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/24 13:40:02 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_struct_map(int i, int curser, char **maps)
{
	int	j;

	j = 0;
	i = 0;
	curser = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'N' || maps[i][j] == 'S' || maps[i][j] == 'E'
				|| maps[i][j] == 'W')
				curser += 1;
			else if (maps[i][j] == '1' || maps[i][j] == '0'
				|| maps[i][j] == ' ')
				curser += 1;
			else
				curser = 0;
			if (curser == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (curser);
}
