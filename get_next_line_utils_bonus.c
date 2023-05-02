/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:15:21 by mbaptist          #+#    #+#             */
/*   Updated: 2023/05/02 16:15:36 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_newline(char *s)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (s[i] && s[i] != '\n')
		s[i++] = '\0';
	if (s[i] == '\n')
	{
		new_line = 1;
		s[i++] = '\0';
		while (s[i])
		{
			s[j++] = s[i];
			s[i++] = '\0';
		}
	}
	return (new_line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*news;
	char	*res;
	int		i;

	if (s2[0] == '\0')
		return (0);
	i = 0;
	news = (char *)malloc(sizeof(char) * ft_strlen(s1) + BUFFER_SIZE + 1);
	res = news;
	if (!news)
	{
		free(news);
		return (NULL);
	}
	while (s1 && s1[i] != 0)
		*news++ = s1[i++];
	if (s1)
		free(s1);
	while (s2 && *s2 != 0 && *s2 != '\n')
		*news++ = *s2++;
	if (*s2 == '\n')
		*news++ = '\n';
	*news = 0;
	return (res);
}
