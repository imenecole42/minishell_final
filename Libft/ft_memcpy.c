/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:42:46 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/17 11:43:59 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	*s1;

	s1 = (unsigned char *)(src);
	s2 = (unsigned char *)(dest);
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
/*
int main () {
   char dest[] = "oldstringeeeeee";
   const char src[]  = "newstringeeeeeeeeeeee";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memcpy(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}
*/