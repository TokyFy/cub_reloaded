/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:21:47 by llalatia          #+#    #+#             */
/*   Updated: 2025/07/24 11:22:03 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	get_rgb(char *str, int j, int count, int val)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	*code;

	r = -1;
	g = -1;
	b = -1;
	i = 0;
	val = 0;
	count = 0;
	code = malloc(sizeof(char) * 5);
	if (!code)
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
		{
			code[j++] = str[i];
			i++;
		}
		code[j] = '\0';
		val = ft_atoi(code);
		if (val < 0 || val > 255)
			return (printf("Code color error : "), free(code), -1);
		if (r == -1)
			r = val;
		else if (g == -1)
			g = val;
		else if (b == -1)
			b = val;
		count += 1;
		while (str[i] && str[i] == ',')
			i++;
	}
	if (count != 3)
		return (printf("Color code error : \n"), free(code), -1);
	return (free(code), rgb_to_color(r, g, b));
}

char	*remove_jumpline(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\n')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
