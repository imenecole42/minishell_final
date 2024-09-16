/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:01:01 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/17 12:17:39 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	t;
	size_t	slen;

	t = 0;
	slen = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (NULL);
	while (t < len && start + t < slen)
	{
		ret[t] = s[start + t];
		t++;
	}
	ret[t] = '\0';
	return (ret);
}
/*
int main()
{
    char src[] = "substr fonction Implementation";

    int m = 7;
    int n = 12;
 
    char* dest = ft_substr(src, m, n);
 
    printf("%s\n", dest);
 
    return 0;
}
*/
