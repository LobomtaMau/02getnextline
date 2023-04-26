/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:07:09 by mbaptist          #+#    #+#             */
/*   Updated: 2023/04/26 16:30:50 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_write(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		free(buff);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*ft_read(int fd, char *buff)
{
	char	*temp;
	int		n_byte;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	n_byte = 1;
	while (n_byte != 0 && !ft_strchr(buff, '\n'))
	{
		n_byte = read(fd, temp, BUFFER_SIZE);
		if (n_byte == -1)
		{
			free(temp);
			free(buff);
			return (NULL);
		}
		temp[n_byte] = 0;
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	if (!buff)
		return (NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_write(buff);
	buff = ft_next(buff);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int	main(void)
{
  char *s;
	int fd = open("teste.txt", O_RDONLY);
	printf("line = %s", get_next_line(fd));
}*/
