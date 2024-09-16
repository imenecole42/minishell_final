/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:22 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/13 17:54:58 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		src;
	char	*dest;
	int		i;

	i = 0;
	src = ft_strlen(s) + 1;
	dest = malloc(src * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char *s;

	s = "ma famille c'est ma vie";
	char *d;
    d = ft_strdup(s);
	printf("%s", ft_strdup(s));
}
*/
