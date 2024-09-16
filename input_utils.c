/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:08:51 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/16 15:06:03 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

int is_sep(char *line)
{

    if (*line == '|' || *line == '>' || *line == '<' || *line == '&')
        return (1);
    return (0);
}

int    begin_sep_error(char *line)
{
    while (is_space(line))
        line++;
    if (*line == '|' || *line == ';')
        return (1);
    return (0);
    
}

int    end_sep_error(char *line)
{
    while (*line)
        line++;
    line--;
    while(is_space(line))
        line--;
    if (is_sep(line))
        return (1);
    return (0);
}



int check_open_quotes(const char *line)
{
    int open_dquotes;
    int open_squotes;

    open_dquotes = 0;
    open_squotes = 0;
    while (*line)
    {
        if (*line == 34 && is_even(open_squotes))
            open_dquotes++;
        else if (*line == 39 && is_even(open_dquotes))
            open_squotes++;
        line++;
    }
    if (!is_even(open_dquotes) || !is_even(open_squotes))
        return(1);
    return(0);
}

int open_quotes(const char *line, int pos)
{
    int open_dquotes;
    int open_squotes;
    int i;

    i = 0;
    open_dquotes = 0;
    open_squotes = 0;
    while (i < pos)
    {
        if (line[i] == 34 && is_even(open_squotes))
            open_dquotes++;
        else if (line[i] == 39 && is_even(open_dquotes))
            open_squotes++;
        i++;
    }
    if (!is_even(open_dquotes) || !is_even(open_squotes))
        return(1);
    return(0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen_mat(char **tab)
{	
	int	y;

	y = 0;
	while (tab[y])
	{
		y++;
	}
	return (y);
}

int    ft_isalnum_mini(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
        return (1);
    return (0);
}