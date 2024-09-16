/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:51:36 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/23 14:15:27 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

int is_quote(char c)
{
    if(c == 34 || c == 39)
        return(1);
    return(0);
}

int is_space(char *s)
{
    if ((*s == ' ') || (*s == '\t'))
        return (1);
    return (0);
}


int check_open_quotes_expand(const char *line, int pos)
{
    int open_dquotes;
    int open_squotes;
    int i;

    i = 0;
    open_dquotes = 0;
    open_squotes = 0;
    printf("pos = %d\n", pos);
    while (line[i] && i < pos)
    {
        if (line[i] == 34 && is_even(open_squotes))
            open_dquotes++;
        else if (line[i] == 39 && is_even(open_dquotes))
            open_squotes++;
        i++;
    }
    printf("i = %d\n", i);
    printf("simple quotes ouvertes = %d\n", open_squotes);
    if (!is_even(open_squotes))
        return(0);
    return(1);
}
