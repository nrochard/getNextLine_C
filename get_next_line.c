/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/23 18:46:59 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int         ret;
	int			i;
	static char *str = "\0";
	char		buff[BUFF_SIZE + 1];

	i = 0;
	if (fd == -1 || line == NULL)
		return (-1);
    if(!(str = malloc(sizeof(char) * (BUFF_SIZE + 1))))
        return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE + 1)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '\n')
			*line = ft_substr(str, 0, i);
		i++;
	}
	return (1);
}

int main(int ac, char **av) 
{
        int fd = 0;

        if (ac >= 2) 
		{
                fd = open(av[1], O_RDONLY);
        }
        int ret = 0;
        char *line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0) 
		{
                printf("{%d}%s\n", ret, line);
         get_next_line(0, &line);
                printf("{%d}%s\n", ret, line);
        }

}