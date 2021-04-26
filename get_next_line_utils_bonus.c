/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalmis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:42:49 by edalmis           #+#    #+#             */
/*   Updated: 2021/04/26 12:21:13 by edalmis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char		*copy;
	size_t		i;

	i = -1;
	copy = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (++i < ft_strlen(s))
		*(copy + i) = *(s + i);
	copy[i] = '\0';
	return (copy);
}

char	*ft_freejoint(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	int		i;

	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		join[i + len1] = s2[i];
	join[i + len1] = '\0';
	return (join);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
