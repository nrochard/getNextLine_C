/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/26 21:44:20 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, i);
	tmp = str;
	str = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
	free(tmp);
	return (str);
}

int		concl_gnl(char **str, char **line, int fd)
{
	if ((ft_strchr(str[fd], '\n')))
	{
		str[fd] = fill_line(str[fd], line);
		return (1);
	}
	if (!(*line = ft_strdup(str[fd])))
		return (-1);
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int		manage_gnl(int fd, char *stock, char **line, char **str)
{
	int			char_read;

	if (ft_strchr(str[fd], '\n'))
	{
		str[fd] = fill_line(str[fd], line);
		return (1);
	}
	while ((char_read = read(fd, stock, BUFFER_SIZE)) > 0)
	{
		stock[char_read] = '\0';
		if (!(str[fd] = ft_strjoin(str[fd], stock)))
			return (-1);
		if (ft_strchr(str[fd], '\n'))
		{
			str[fd] = fill_line(str[fd], line);
			return (1);
		}
	}
	return (concl_gnl(str, line, fd));
}

int		get_next_line(int fd, char **line)
{
	static char *str[1024];
	char		stock[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, stock, 0) == -1)
		return (-1);
	*line = NULL;
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	return (manage_gnl(fd, stock, line, str));
}
