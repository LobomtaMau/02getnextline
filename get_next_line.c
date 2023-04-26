/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:20:12 by mbaptist          #+#    #+#             */
/*   Updated: 2023/04/26 17:28:31 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_write(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	return (str);
}

char	*ft_next(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	str = ft_strdup(buff + i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;
	char		*temp;
	int			n_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_write(buff);
	temp = buff;
	buff = ft_next(buff);
	free(temp);
	return (line);
}
