/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/30 12:43:32 by nrochard         ###   ########.fr       */
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
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, i);
	str = &str[i + 1];
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	int         j;
	static char *str = "\0";

	i = 0;
	j = 0;

	// if(!(str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	// 	return (-1);
	// if(!(tmp_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(tmp_str) + 1))))
	// 	return (-1);
	str = read_fd(str, fd);
	printf("STR READ = [%s]\n", str);

	if (ft_strchr(str, '\n') != NULL || str[i])
	{
		printf("ici\n");
		str = fill_line(str, line, i);
		return (1); 
	}
	// while (ft_strchr(str, '\n') == NULL)
	// {
	// 	str = read_fd(str, fd);
	// 	if (ft_strchr(str, '\n') != NULL)
	// 	{
	// 		*line = fill_line(str, line, i);
	// 		return (1); 
	// 	}
	// }
	return (0);
}
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	(void)argc;
	
	fd = open((argv[1]), O_RDONLY);

	// ret = get_next_line(fd, &line);
	// printf("%d -> %s\n", ret, line);
	// free(line);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d -> %s\n", ret, line);
	    free(line);
	}
	printf("%d -> %s\n", ret, line);
	    free(line);

	close(fd);
	return (0);
}