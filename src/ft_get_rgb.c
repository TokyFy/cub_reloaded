/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:21:47 by llalatia          #+#    #+#             */
/*   Updated: 2025/08/27 14:07:58 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	parse_value(char *str, int *i)
{
	char	code[5];
	int		j;
	int		val;

	j = 0;
	while (str[*i] && (ft_isdigit(str[*i]) || str[*i] == '-' || str[*i] == '+')
		&& j < 4)
		code[j++] = str[(*i)++];
	code[j] = '\0';
	if (j == 0)
		return (ft_error("Missing color value"), -1);
	val = ft_atoi(code);
	if (val < 0 || val > 255)
		return (ft_error("Invalid color code"), -1);
	return (val);
}

static void	rgb_init(int *r, int *g, int *b)
{
	*r = -1;
	*g = -1;
	*b = -1;
}

int	get_rgb(char *str, int j, int count, int val)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0 * j;
	rgb_init(&r, &g, &b);
	while (str[i])
	{
		val = parse_value(str, &i);
		if (val == -1)
			return (-1);
		if (r == -1)
			r = val;
		else if (g == -1)
			g = val;
		else if (b == -1)
			b = val;
		count++;
		while (str[i] && str[i] == ',')
			i++;
	}
	if (count != 3)
		return (ft_error("RGB must contain exactly 3 values"), -1);
	return (rgb_to_color(r, g, b));
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
