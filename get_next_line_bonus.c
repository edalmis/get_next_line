/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalmis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:49:35 by edalmis           #+#    #+#             */
/*   Updated: 2021/04/26 12:24:10 by edalmis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_search_ch(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_cutline(int index, char *remain, char **line)
{
	int	len;

	*line = ft_substr(remain, 0, index);
	index++;
	len = ft_strlen(remain + index) + 1;
	remain = ft_memmove(remain, remain + index, len);
	return (1);
}

static	void	ft_lastclean(char **remain, char **line)
{
	if (remain)
	{
		*line = ft_strdup(*remain);
		free (*remain);
		*remain = NULL;
	}
	else
		*line = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char	*remain[256];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	ret = 1;
	if (remain[fd] && ft_search_ch(remain[fd], '\n') != -1)
	{
		index = ft_search_ch(remain[fd], '\n');
		return (ft_cutline(index, remain[fd], line));
	}
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		remain[fd] = ft_freejoint(remain[fd], buf);
		index = ft_search_ch(remain[fd], '\n');
		if (index != -1)
			return (ft_cutline(index, remain[fd], line));
	}
	ft_lastclean(&remain[fd], line);
	return (0);
}
