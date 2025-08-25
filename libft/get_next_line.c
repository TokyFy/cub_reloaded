/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:51:41 by llalatia          #+#    #+#             */
/*   Updated: 2024/04/29 14:29:22 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*have_line(int fd, char *s)
{
	char	*buffer;
	int		readed;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	readed = 1;
	while (!ft_strchr(s, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (free(buffer), s);
		buffer[readed] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else
		{
			s = ft_strjoin(s, buffer);
		}
	}
	free(buffer);
	return (s);
}

char	*the_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*have_next_line(char *s)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	next_line = malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
	{
		next_line[j] = s[i];
		i++;
		j++;
	}
	next_line[j] = '\0';
	free(s);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;

	ret = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = have_line(fd, line);
	if (!line)
		return (free(line), NULL);
	ret = the_line(line);
	line = have_next_line(line);
	if (!line)
		line = NULL;
	else if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (ret);
}
