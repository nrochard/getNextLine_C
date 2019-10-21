/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:26 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/21 11:27:19 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<fcntl.h>

size_t read(int fd, void *buffer, size_t n)
{

}

int	get_next_line(int fd, char **line)
{
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
}

int main()
{
    char c;
    int fd;

    fd =  open("/Users/nrochard/Desktop/get_next_line/test", O_RDONLY);
    if (fd == -1)
	{         
        fprintf("impossible d'ouvrir le fichier\n");
        exit(1);
    }
    while (read(fd, &c, 1) > 0 )
        putchar(c);

    close(fd);
    return (0);
}