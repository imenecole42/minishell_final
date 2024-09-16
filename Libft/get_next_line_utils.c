/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:43:58 by imraoui           #+#    #+#             */
/*   Updated: 2022/06/13 16:12:12 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen1(s1) + ft_strlen1(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen1(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen1 (s1)];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr1( char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != c))
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (*s == ((char)c))
		return ((char *)s);
	return (NULL);
}
