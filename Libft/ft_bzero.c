/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:03:59 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/13 08:13:44 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
		s2[i++] = '\0';
}
/*
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore bzero(): %s\n", str);
	ft_bzero(str +1,10);
	//bzero(str + 13,44);
    printf("After bzero():  %s", str);
    return 0;
}
*/
