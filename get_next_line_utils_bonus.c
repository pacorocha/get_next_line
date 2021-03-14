/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:27:08 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/11 12:43:20 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	if ((c_dest != NULL) || (c_src != NULL))
	{
		while (n--)
		{
			*(c_dest++) = *(c_src++);
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	if (s3)
	{
		ft_memcpy(s3, s1, len_s1);
		ft_memcpy(s3 + len_s1, s2, len_s2 + 1);
	}
	return (s3);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	while (*s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}
