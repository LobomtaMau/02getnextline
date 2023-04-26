/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:13:27 by mbaptist          #+#    #+#             */
/*   Updated: 2023/04/26 17:13:28 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			bytes_rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_strdup("");
	temp = ft_strdup("");
	bytes_rd = 1;
	while (bytes_rd > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_rd = read(fd, temp, BUFFER_SIZE);
		if (bytes_rd == -1)
			return (NULL);
		temp[bytes_rd] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	if (ft_strchr(buffer, '\n'))
	{
		line = ft_strsub(buffer, 0, ft_strchr(buffer, '\n') - buffer);
		temp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strsub(temp, ft_strchr(temp, '\n') - temp + 1,
				ft_strlen(temp));
		free(temp);
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
