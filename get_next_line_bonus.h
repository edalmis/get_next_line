/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalmis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:41:49 by edalmis           #+#    #+#             */
/*   Updated: 2021/04/26 12:22:28 by edalmis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
char		*ft_strdup(char *s);
char		*ft_freejoint(char *s1, char *s2);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_substr(char const *s, int start, int len);

#endif
