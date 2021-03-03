/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:44:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/03 12:04:41 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		**buf_gtr_t_line(char **return_string, char *bufferline,
			size_t linesize, char **line)
{
	char	*str_tmp;
//	int		i;
	ft_bzero(str_tmp, linesize);
	str_tmp = ft_strchr((char *)return_string, '\n');
	return_string[linesize + 1] = '\0';
	str_tmp = (char *)*return_string;
	*line = str_tmp;
//	free (bufferline);
//	free (str_tmp);
	linesize = linesize + 1;//isso é pra tapear o gcc
	return (line);
}

char		**buf_less_eq_t_line(char **return_string, char *bufferline,
			size_t linesize, char **line)
{
	return_string = (char **)bufferline;
	return_string[linesize + 1] = '\0';
	line = return_string;
//	free (bufferline);
	linesize = linesize + 1;//isso é pra tapear o gcc
	return (line);
}

size_t		len_to_nl(char *readbuffer, bool nl_found)
{
	int i;
	i = 0;
	while (readbuffer[i] != 0)
	{
		if (readbuffer[i] == '\n')
		{
		nl_found = true;
		i++;
		return ((size_t)i);
		}
		i++;
	}
	return (i); // qualquer \n indevido, incluir i + 1
}

int		get_next_line(int fd, char **line)
{
	static char readbuffer[BUFFER_SIZE + 1];
	int	readout;
	char *bufferline;
	int *buffers_end;
	static char **return_string;
	//static int	*last_read_char;
	static bool nl_found;
	size_t linesize;

	return_string = '\0';
	nl_found = false;
	linesize = 0;

	readout = read(fd, readbuffer, BUFFER_SIZE);

	if (readout <= 0)
		return(readout == 0) ? (0):(-1);
	printf("%s\n", readbuffer);
	printf("%i\n", readout);
	printf("%d\n", nl_found);
	bufferline = ft_strdup(readbuffer + 1);
	linesize = len_to_nl(readbuffer, nl_found);
	if (linesize <= 0)
	{
	//	free(bufferline);
		return (0);
	}
	if (BUFFER_SIZE > linesize)
		buf_gtr_t_line(return_string, bufferline, linesize, line);// << VAZANDO MEMÓRIA OLHAR memset
	buf_less_eq_t_line(return_string, bufferline, linesize, line); 
	//free (bufferline);
	return (1);
}
