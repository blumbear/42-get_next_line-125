/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:30:48 by ttaquet           #+#    #+#             */
/*   Updated: 2023/12/07 15:17:30 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1] = {"\0"};
	char		*line;

	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (free(line), NULL);
	if (buffer[fd][0] != '\0')
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (free(line), NULL);
		if (ft_not_in(line, '\n') > -1)
			line[ft_not_in(line, '\n') + 1] = '\0';
	}
	line = ft_read2buff(line, buffer[fd], fd);
	if (line == NULL)
		return (NULL);
	if (ft_not_in(buffer[fd], '\n') > -1)
		ft_strcpy(buffer[fd], buffer[fd] + ft_not_in(buffer[fd], '\n') + 1);
	return (line);
}

char	*ft_read2buff(char *line, char *buffer, int fd)
{
	int	bytes_read;

	bytes_read = 1;
	while (ft_not_in(line, '\n') == -1 && bytes_read != 0)
	{
		buffer[0] = '\0';
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
	}
	if (ft_not_in(line, '\n') > -1)
		line[ft_not_in(line, '\n') + 1] = '\0';
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
