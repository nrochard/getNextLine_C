/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/24 19:11:00 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int         ret;
	int			i;
    int         j;
	static char *str;
	char		stock[BUFFER_SIZE + 1];

	i = 0;
    j = 0;
    if(!(str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
	if ((ret = read(fd, stock, BUFFER_SIZE)) > 0)
	{
		stock[ret] = '\0';
        printf("ret = %d\n", ret);
		str = ft_strjoin(str, stock);
	}
    printf("str = %s\n", str);
    printf("stock = %s\n", stock);

    while (str[i] != '\n' && str[i] != '\0')
    	i++;
	
    if (i == 0)
		(*line) = ft_strdup("");
	else
	{
		*line = ft_substr(str, 0, i);
		str = &str[i + 1];
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
    (void)ac;
    
	line = NULL;
	fd = open(av[1], O_RDONLY);
    get_next_line(fd, &line);
    printf("resulat = [%s]\n", line);
	// while ((ret = (get_next_line(fd, &line))) > 0)
	// {
	// 	printf("%s\n", line);
	// }
	close(fd);
}