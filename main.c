/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:50:28 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/24 10:21:14 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

void    sig_handler(int signum)
{

    if (signum == SIGINT)
    {
        write(1, "\n", 1);
        rl_on_new_line();
        //rl_replace_line("", 0);
        rl_redisplay();
    }

}

char    *display_prompt(void)
{
    static char *prompt;

    prompt = NULL;
    // signal(SIGINT, sig_handler);
    // signal(SIGQUIT,SIG_IGN);
    if (prompt)
    {
        free(prompt);
        prompt = NULL;
    }
    prompt = readline("🐚> ");
    if (!prompt)
    {
        printf("BYE BYE 😘\n");
        exit(0);
    }
    if(ft_strlen(prompt) > 0)
        add_history(prompt);
    return (prompt);
}

int check_input(t_data *data)
{
    char    *tmp;

    tmp = NULL;
    tmp = ft_strdup(data->line);
    if (ft_strlen(tmp) > MAXLINE)
    {
        printf(BOLD_YELLOW"command line is too long\n You want to break the parsing or what?\n"RESET);
        free (data->line);
        free (tmp);
        return(0);
    }
    if (check_open_quotes(tmp) == TRUE)
    {
        printf(BOLD_YELLOW"error: check your quotes!\n"RESET);
        free (data->line);
        free (tmp);
        return(0);
    }
    if ((begin_sep_error(tmp) == TRUE) || end_sep_error(tmp) == TRUE)
    {
        printf("syntax error near unexpected token `newline' \n");
        free (data->line);
        free (tmp);
        return(0);
    }
    free(tmp);
    return(1);
}

int main(int argc, char **argv, char **env)
{
    (void)  argv;
    t_data  data;

    if (argc == 1)
    {
        if(init_struct(&data, env) == FALSE)
            return(1);  //data exit status = 1
        while (1)
        {
            signal(SIGINT, sig_handler);
            signal(SIGQUIT,SIG_IGN);
            data.line = ft_strdup(display_prompt());
            if (check_input(&data) == FALSE)
                return (1);
            replace(&data);
            data.token = read_input(data.line);
            // //printf("ici\n");
            print_token(&data.token);
            // // //data.cmds = init_command();
            data.cmds = parse_cmd_table(data.token);
            print_liste_cmd(&data.cmds);
            //ft_basic_functions(line, argv);
            //read_command(command, parameters); // read input from terminal
        //if (fork() != 0) //parent
           // wait(NULL); // wait for child
        //else
           // execve (command, parameters, 0); // execute command
        //return (0);
        }
    }
    else
        printf("error, too much arguments\n");

    return(0);
}
