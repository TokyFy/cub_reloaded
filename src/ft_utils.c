/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:45:09 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/23 12:45:24 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c > 8 && c < 10) || (c > 10 && c < 14))
		return (1);
	return (0);
}

int	ft_compare(char *str, char *string)
{
	int	i;

	i = 0;
	if(ft_strlen(str) != ft_strlen(string))
		return 0;
	while (str[i] != '\0')
	{
		if (str[i] != string[i])
			return (0);
		i++;
	}
	return (1);
}

char	*b_space(int n)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (n + 1));
	if (!new_str)
		return (NULL);
	while (i < n)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[n] = '\0';
	return (new_str);
}

char	**new_maps(t_data *data)
{
	int		i;
	char	**new_maps;
	char	*new_map;

	i = 0;
	new_maps = malloc(sizeof(char *) * (data->heigth + 1));
	if (!new_maps)
		return (NULL);
	while (i < data->heigth)
	{
		new_map = b_space(data->width);
		new_maps[i] = ft_memcpy((char *)new_map, (char *)data->maps[i],
				ft_strlen((const char *)data->maps[i]));
		new_maps[i][data->width] = '\0';
		i++;
	}
	new_maps[data->heigth] = NULL;
	return (new_maps);
}

void	add_the_line(t_list *head, char *line)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = head;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return ;
	tmp->content = ft_strdup(line);
	tmp->next = NULL;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
}
