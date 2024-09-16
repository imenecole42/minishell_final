/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:21:35 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/13 09:22:08 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned int	i;

	s1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}
/*
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);

    // Remplissez 8 caractères à partir de str[13] avec '.'
    //memset(str + 13, '.', 8*sizeof(char));
	ft_memset(str + 13, '.', 8*sizeof(char));
    printf("After memset():  %s", str);
    return 0;
}
*/
