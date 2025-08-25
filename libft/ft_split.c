/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 08:27:38 by llalatia          #+#    #+#             */
/*   Updated: 2024/03/06 15:14:47 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count += 1;
		i++;
	}
	return (count);
}

static char	*mot(const char *str, int i, int j)
{
	char	*mot;
	int		k;

	k = 0;
	mot = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		mot[k] = str[i];
		k++;
		i++;
	}
	mot[k] = '\0';
	return (mot);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	int				k;
	char			**liste_mots;

	liste_mots = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!liste_mots)
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			liste_mots[j] = mot(s, k, i);
			k = -1;
			j++;
		}
		i++;
	}
	liste_mots[j] = 0;
	return (liste_mots);
}
