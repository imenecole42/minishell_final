/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:33 by imraoui           #+#    #+#             */
/*   Updated: 2022/05/25 13:04:56 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count && (count * size / count) != size)
		return (NULL);
	dest = malloc(count * size);
	if (!dest)
		return (NULL);
	ft_bzero((char *)dest, count * size);
	return ((char *)dest);
}
/*
int main() {
    
    int i;
    int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );

    // Un petit test sur le bon fonctionnement de calloc 
    assert( pointer != NULL );

    // Le dernier élément du tableau ne sera pas affecté par la 
    // boucle mais n'oubliez pas que calloc initialise de toute 
    // façon à 0 chaque octet. 
    for ( i=0; i<INT_NUMBER-1; i++ ) {
        pointer[i] = i;
    }

    // On affiche le contenu du tableau d'entier //
    // Ce qui donne : 0 1 2 3 4 5 6 7 8 0 
    for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );

    // On libère le bloc de mémoire alloué dynamiquement 
    free( pointer );

    return 0;
}
*/
