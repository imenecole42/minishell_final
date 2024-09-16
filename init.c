/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:44:49 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/15 16:53:31 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

int     dup_env(t_data *data, char **env)
{
    int i;
    int size;

    i = -1;
    size = 0;
    while (env[++i] != NULL)
    {
        size++;
        //printf(BOLD_PURPLE"env[%d] == %s\n"RESET, i, env[i]);
    }
    data->env = ft_calloc(size + 1, sizeof(char**));
    if (!data->env)
        return(0);
    i = -1;
    while (env[++i] != NULL)
    {
        data->env[i] = ft_strdup(env[i]);
        if (!data->env[i])
            return(0);
    }
    i = -1;
    while (data->env[++i] != NULL)
    {
        size++;
        //printf(BOLD_RED"env[%d] == %s\n"RESET, i, data->env[i]);
    }
    return(1);
}

int    init_struct(t_data *data, char **env)
{
    // int mode;

    // mode = isatty(STDIN_FILENO);
    // if (mode != TRUE)
    //     (EXIT_FAILURE); // faire fonction pour quitter proprement
    //data = malloc(sizeof(data));
    //ft_bzero(data, sizeof(t_data));
    //(void) env;
    data->line = NULL;
    //data->export = NULL;
    data->cmds = NULL;
    data->env = NULL;
    data->exit_status = 0;
    data->argc = 0;
    data->token = NULL;
    if (dup_env(data, env) == FALSE)
    {
        printf("error : initialization of environment");
        return (0);
    }
    return(1);
}
