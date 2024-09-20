/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:05:30 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/20 19:05:37 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1));
	if (!line)
	{
		buffer = NULL;
		return (free(buffer), NULL);
	}
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((ft_strlen(buffer) - i + 1));
	if (!line)
	{
		buffer = NULL;
		return (free(buffer), NULL);
	}
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j++] = '\0';
	return (free(buffer), line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	int		byte_read;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (free(buffer), NULL);
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(temp), NULL);
		if (byte_read == 0)
			break ;
		temp[byte_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	return (free(temp), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	if (ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = first_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	buffer = next_line(buffer);
	if (!buffer)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	return (line);
}
