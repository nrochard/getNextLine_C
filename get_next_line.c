/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/11/03 14:14:15 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *str, char **line, int i)
{
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, (i + 1));
	str = &str[i + 1];
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	static char *str = "\0";
	int			char_read;
	char		stock[BUFFER_SIZE + 1];

	i = 0;
	char_read = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, stock, 0) == -1)
		return (-1);
	while ((char_read = read(fd, stock, BUFFER_SIZE)) > 0)
	{
		stock[char_read] = '\0';
		str = ft_strjoin(str, stock);
		if (ft_strchr(str, '\n'))
		{
			str = fill_line(str, line, i);
			return (1);
		}
	}
	if (str[i] != '\0' && char_read == 0)
	{
		str = fill_line(str, line, i);
		if ((ft_strchr(*line, '\n')))
			return (1);
		if (!(ft_strchr(*line, '\n')))
			return (0);
	}
	if (str[i] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
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
	close(fd);
	return (0);
}
