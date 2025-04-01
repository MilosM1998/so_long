/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:40:49 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/01 20:50:29 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *buff, int readed)
{
	char	*temp;

	while (!(my_strchr(buffer, '\n')) && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (free_all(&buffer));
		if (readed == 0)
			break ;
		buff[readed] = '\0';
		temp = buffer;
		buffer = my_strjoin(buffer, buff);
		free(temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

static char	*allocate_line(int fd, char *buffer)
{
	char	*buff;
	int		readed;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free_all(&buffer));
	readed = 1;
	buffer = read_line(fd, buffer, buff, readed);
	free(buff);
	return (buffer);
}

static char	*find_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*refresh_buff(char *buffer)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_buff = malloc(sizeof(char) * (my_strlen(buffer) - i + 1));
	if (!new_buff)
		return (free_all(&buffer));
	j = 0;
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (!buffer)
	{
		buffer = my_strdup("");
		if (!buffer)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_all(&buffer));
	buffer = allocate_line(fd, buffer);
	if (!buffer || *buffer == '\0')
		return (free_all(&buffer));
	line = find_line(buffer);
	if (!line)
		return (free_all(&buffer));
	buffer = refresh_buff(buffer);
	if (!buffer || *buffer == '\0')
		(free_all(&buffer));
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
