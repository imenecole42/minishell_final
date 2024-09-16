/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:45 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/20 18:42:41 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
/*
int	main(void)
{	
	unsigned int n;
	char dest[] = " ";
	char src[] = "salut toi ";
	n = 4;
	ft_strlcpy(dest,src,n);
	//strlcpy(dest,src,n);
	printf("%ld",ft_strlcpy(dest,src,n));
	return(0);
}
*/
