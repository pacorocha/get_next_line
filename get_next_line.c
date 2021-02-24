/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:44:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/02/24 12:44:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t          ft_strlen(const char *str)
{
        int i;

        i = 0;
        while (str[i] != 0)
        {
                i++;
        }
        return (i);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
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

char    *ft_strdup(const char *s)
{
        int             len;
        char    *dest;

        len = ft_strlen(s);
        if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
                return (NULL);
        ft_strlcpy(dest, s, (len + 1));
        return (dest);
}


int		get_next_line(int fd, char **line)
{
	static char readbuffer[BUFFER_SIZE + 1]; /* static ?? ,*/
	size_t bufsize;

	bufsize = read(fd, readbuffer, BUFFER_SIZE);
	readbuffer[BUFFER_SIZE] = '\0';
	*line = ft_strdup(readbuffer);
	return (1);
	/* readbuffer = &bufsize; */

	if (BUFFER_SIZE <= 0)
	{
		free(readbuffer);
		return (-1);
	}

}
