/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/25 20:03:34 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *str, char **line, int i)
{
	char *tmp;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, (i + 1));
	tmp = str;
	str = ft_substr(str, i + 1, ft_strlen(str));
	free(tmp);
	return (str);
}

int     concl_gnl(char **str, int i, char **line)
{
	if (*str[i] == '\0')
		if (!(*line = ft_strdup("")))
			return (-1);
	return (0);
}

int     manage_gnl(int fd, char *stock, char **line, char **str)
{
	int			char_read;
	int			i;

	i = 0;
	while ((char_read = read(fd, stock, BUFFER_SIZE)) > 0)
	{
		stock[char_read] = '\0';
		if (!(*str = ft_strjoin(*str, stock)))
			return (-1);
		if (ft_strchr(*str, '\n'))
		{
			*str = fill_line(*str, line, i);
			return (1);
		}
	}
	if (*str[i] != '\0' && char_read == 0)
	{
		*str = fill_line(*str, line, i);
		if ((ft_strchr(*line, '\n')))
			return (1);
		if (!(ft_strchr(*line, '\n')))
			return (0);
	}
	return (concl_gnl(str, i, line));
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char		stock[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, stock, 0) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	return (manage_gnl(fd, stock, line, &str));
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf(" %d - > read = %s", ret, line);
		free(line);
	}
	printf(" %d - > read = %s\n", ret, line);
	free(line);
	close(fd);
	while(1);
	return (0);
}
