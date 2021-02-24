/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:47:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/02/24 19:59:55 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

char		*ft_strdup(const char *s)
{
	int             len;
	char    *dest;

	len = ft_strlen(s);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(dest, s, (len + 1));
	return (dest);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstlen)
{
	size_t i;
	size_t j;

	if (dstlen <= ft_strlen(dst))
		return (ft_strlen(src) + dstlen);
	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (i + j < dstlen - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}