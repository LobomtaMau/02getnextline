/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:07:09 by mbaptist          #+#    #+#             */
/*   Updated: 2023/05/02 15:35:49 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	content[BUFFER_SIZE];
	int			c;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	str = ft_strjoin(0, content);
	if (ft_newline(content) > 0)
		return (str);
	c = read(fd, content, BUFFER_SIZE);
	if (c < 0)
	{
		free(str);
		return (NULL);
	}
	while (c > 0 || *content != 0)
	{
		str = ft_strjoin(str, content);
		if (ft_newline(content) > 0)
			break ;
		c = read(fd, content, BUFFER_SIZE);
	}
	return (str);
}
