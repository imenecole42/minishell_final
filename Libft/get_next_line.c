/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:00:17 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/21 17:30:22 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_select_g1(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		dest = (char *) malloc(sizeof(char) * (i + 2));
	else if (str[i] == '\0')
		dest = (char *) malloc(sizeof(char) *(i + 1));
	if (!dest)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		dest[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		dest[j++] = '\n';
	dest[j] = '\0';
	return (dest);
}

char	*ft_select_g2(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	if (str[i] == '\n')
		dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	while (str && str[i])
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*get_read_line(int fd, char *str)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*temp;
	int			res;

	res = 1;
	while (res > 0 && (!str || !ft_strchr(str, '\n')))
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		buff[res] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*temp;
	char		*ligne;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read_line(fd, str);
	if (!str)
		return (NULL);
	if (!str[0])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ligne = ft_select_g1(str);
	temp = ft_select_g2(str);
	if (str != NULL)
		free(str);
	str = temp;
	return (ligne);
}
