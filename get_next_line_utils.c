/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:26:21 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/23 18:54:48 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[i] != '\0')
		i++;
	len = i + 1;
	i = 0;
	if (!(dest = malloc(sizeof(char) * len)))
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(new = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new[k++] = s1[i++];
	while (s2[j] != '\0')
		new[k++] = s2[j++];
	new[k] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
