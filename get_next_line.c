/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/29 11:24:01 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_fd(char *str, int fd)
{
	int ret;
	char stock[BUFFER_SIZE + 1];


	ret = 0;
	if ((ret = read(fd, stock, BUFFER_SIZE)) > 0)
	{	
		stock[ret] = '\0';
		str = ft_strjoin(str, stock);
	}
	return (str);
}

char	*fill_line(char *str, char **line, int i)
{
	while (str[i++] != '\0')
		{
			if (str[i] == '\n')
			{
				if (i == 0)
					(*line) = ft_strdup("");
				else
				{
					*line = ft_substr(str, 0, i);
					str = &str[i + 1];
				}
			}
		}
	return (*line);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	int         j;
	static char *str;

	i = 0;
	j = 0;
	if(!(str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	str = read_fd(str, fd);
	if (ft_strchr(str, '\n') != NULL)
	{
		*line = fill_line(str, line, i);
		return (1); 
	}
	while (ft_strchr(str, '\n') == NULL)
	{
		str = read_fd(str, fd);
		if (ft_strchr(str, '\n') != NULL)
		{
			*line = fill_line(str, line, i);
			return (1); 
		}
	}
	free(str);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while (i < 50)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		ret = get_next_line(fd, &line);
		printf("|%s|\n", line);
		i++;
	}
}	