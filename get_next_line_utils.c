/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:47:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/03 10:09:37 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memset(void *s, int c, size_t len)
{
	unsigned char *p;

	p = s;
	while (len--)
	{
		*p++ = (unsigned char)c;
	}
	return (s);
}

void		ft_bzero(void *s, size_t n)
{
	if (sizeof(s) >= 0)
		ft_memset(s, '\0', n);
}

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

size_t		ft_strlcpy(char *dst, const char *src, size_t size) // juntar essas duas  v v v 
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

char        *ft_strdup(const char *s)
{
    size_t    size;
    char    *dest;

    size = ft_strlen(s) + 1;
    dest = malloc(size);
    if (dest == NULL)
        return (NULL);
    ft_memcpy(dest, s, size);
    return (dest);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char    *c_dest;
    char    *c_src;

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

char		*ft_strchr(const char *s, int c)
{
		while (*s)
		{
				if (*s == (char)c)
						return ((char *)s);
				s = s + 1;
		}
		if ((char)c == '\0')
				return ((char *)s);
		else
				return (NULL);
}
