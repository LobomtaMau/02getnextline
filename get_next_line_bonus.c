/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:18:03 by mbaptist          #+#    #+#             */
/*   Updated: 2023/05/02 16:24:43 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	content[FOPEN_MAX][BUFFER_SIZE + 1]; //add fopen + 1
  
	int			c;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	str = ft_strjoin(0, content[fd]); //add FD
	if (ft_newline(content[fd]) > 0) //add FD
		return (str);
	c = read(fd, content[fd], BUFFER_SIZE); //add FD
	if (c < 0)
	{
		free(str);
		return (NULL);
	}
	while (c > 0 || *content[fd] != 0) //add FD
	{
		str = ft_strjoin(str, content[fd]); //add FD
		if (ft_newline(content[fd]) > 0) //add FD
			break ;
		c = read(fd, content[fd], BUFFER_SIZE);//add FD
	}
	return (str);
}
