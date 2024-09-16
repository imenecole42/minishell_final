/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:46:37 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/23 15:10:44 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

/*char	*ft_strjoin_char(char const *s1, char s2)
{
	char	*ret;
	size_t	s1_len;
    
    ret = NULL;
    s1_len = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(&s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, &s2, 2);
	return (ret);
}*/

char *ft_strdup_char(char c)
{
    char  *dest;
    
    //if(!c)
        //return(NULL);
    dest = malloc(sizeof(char)*2);
    dest[0] = c;
    dest[1] = '\0';
    return(dest);
}

char *env_finder(char *line, int start, int end)
{
    int i;
    char *str;
    char *dup;

    i = 0;
    str = NULL;
    dup = ft_strdup(line);
    str = malloc(sizeof(char) * (end - start + 1));
    str[(end - start)] = '\0';
    while (start < end)
    {
        str[i] = dup[start];
        i++;
        start++;
    }
    free(dup);
    return(str);
}

void    replace(t_data *data)
{ 
    int dollar;
    int i;
    int start;
    int end;
    char *env;
    char *new;

    i = 0;
    start = 0;
    end = 0;
    dollar = 0;
    env = NULL;
    new = NULL;
    while(data->line[i])
    {
        while (data->line[i] == '$' && data->line[i])
        {
            if(data->line[i] && check_open_quotes_expand(data->line, i) && ft_isalnum_mini(data->line[i + 1]))
                    {dollar = 1;}
            else 
               { new = ft_strjoin_hinda(new, ft_strdup_char(data->line[i]));}
            i++;
        }
        if (dollar == 1)
        {
            start = i;
            while (ft_isalnum_mini(data->line[i]) && data->line[i])
                i++;
            end = i;
            env = env_finder(data->line, start, end);
            env = check_var(env, data);
            if(env)
            {
                env = ft_select1(env);
                new = ft_strjoin_hinda(new, env);
                free(env);
            }
            dollar = 0;
        }
        new = ft_strjoin_hinda(new, ft_strdup_char(data->line[i]));
        if (data->line[i] != '$' && data->line[i])
            i++; 
    }
    data->line = ft_strdup(new);
    printf("expand = %s\n", new);
    free(new);
    }
 

