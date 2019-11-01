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
	int 		ret = 0;
	char		stock[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);

	while ((ret = read(fd, stock, BUFFER_SIZE)) > 0)
	{	
		stock[ret] = '\0';
		str = ft_strjoin(str, stock);
	}
	if (ret > 0 && (ft_strchr(str, '\n')))
	{
		str = fill_line(str, line, i);
	    	return (1); 
	}
	if (ret == 0 && str[i] != '\0')
	{
		str = fill_line(str, line, i);
	    	return (1);
	}
	return (0);
}