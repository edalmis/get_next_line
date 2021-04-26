/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalmis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:52:04 by edalmis           #+#    #+#             */
/*   Updated: 2021/04/26 11:40:52 by edalmis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*remain = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	ret = 1;
	if (remain && ft_search_ch(remain, '\n') != -1)
	{
		index = ft_search_ch(remain, '\n');
		return (ft_cutline(index, remain, line));
	}
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		remain = ft_freejoint(remain, buf);
		index = ft_search_ch(remain, '\n');
		if (index != -1)
			return (ft_cutline(index, remain, line));
	}
	ft_lastclean(&remain, line);
	return (0);
}
