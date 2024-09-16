/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:43:24 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/16 16:18:15 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_special_char(char *line, int i)
{
    if (line[i] == '|')
        return (1);
    else if (line[i] == '>' && line[i + 1] != '>')
        return (2);
    else if (line[i] == '<' && line[i + 1] != '<')
        return (3);
    else if (line[i] == '>' && line[i + 1] == '>')
        return (4);
    else if (line[i] == '<' && line[i + 1] == '<')
        return (5);
    else if (line[i] == '\'')
        return (6);
    else if (line[i] == '\"')
        return (7);
    else if (line[i] == '$')
        return (8);
    else if ((line[i] > 8 && line[i] < 14) || line[i] == 32)
        return (9);
    else if (line[i] == '\0')
        return (10);
    else
        return (0);
}

int is_d_quotes(char *line, int i)
{
    if (line[i] == '\"')
    {
        return (1);
    }
    return (0);
}

int is_s_quotes(char *line, int i)
{
    if (line[i] == '\'')
    {
        return (1);
    }
    return (0);
}

int set_status(enum e_state status, char *str, int i)
{
    if (str[i] == '\'' && status == DEFAULT)
        status = SQUOTE;
    else if (str[i] == '\"' && status == DEFAULT)
        status = DQUOTE;
    else if (str[i] == '\'' && status == SQUOTE)
        status = DEFAULT;
    else if (str[i] == '\"' && status == DQUOTE)
        status = DEFAULT;
    //else if (str[i] == '\'' && status == DQUOTE)
        //status = DEFAULT;
    //else if (str[i] == '\'' && status == SQUOTE)
        //status = DEFAULT;
    return (status);
}

int save_word(t_token **lexer, char *line, enum e_state status)
{
    int i;

    i = 0;
    while (is_special_char(line, i) == FALSE)
    {
        i++;
    }
    ft_lstadd_back_token(lexer, create_token(line, i, WORD, status));
    //print_token(&lexer);
    //printf("save word : %s\n", line);
    //printf("save word_struct : %s\n", tmp->value);
    //printf("save word_len : %d\n", tmp->len);
    //printf("save word_type : %d\n", tmp->type);
    //printf("save word_status : %d\n", tmp->qstatus);
    //printf("save_word i: %d\n", i);
    return (i);
}

int save_dquotes(t_token **lexer, char *line, enum e_state status)
{
    int i;

    i = 0;
    while (is_d_quotes(line, i) == FALSE)
    {
        i++;
    }
    ft_lstadd_back_token(lexer, create_token(line, i, WORD, status));
    return (i);
}

int save_squotes(t_token **lexer, char *line, enum e_state status)
{
    int i;

    i = 0;
    while (is_s_quotes(line, i) == FALSE)
    {
        i++;
    }
    ft_lstadd_back_token(lexer, create_token(line, i, WORD, status));
    return (i);
}

int save_redirection(t_token **lexer, char *line, int i, enum e_state status)
{
    int j;

    j = i;
    if (is_special_char(line, i) == 2)
       ft_lstadd_back_token(lexer, create_token(line + (i++), 1, REDIR_OUT, status));
    else if (is_special_char(line, i) == 3)
        ft_lstadd_back_token(lexer, create_token(line + (i++), 1, REDIR_IN, status));
    else if (is_special_char(line, i) == 4)
    {
        ft_lstadd_back_token(lexer, create_token(line + (i++), 2, DREDIR_OUT, status));
        i++;
    }
    else if (is_special_char(line, i) == 5)
    {
        ft_lstadd_back_token(lexer, create_token(line + (i++), 2, HEREDOC, status));
        i++;
    }
    return (i - j);
}

int tokenizer(t_token **lexer, char *line, int i, enum e_state status)
{
    if (is_special_char(line, i) == FALSE)
        i += save_word(lexer, line + i, status);
    else if (is_special_char(line, i) == 1)
        ft_lstadd_back_token(lexer, create_token(line + (i++), 1, PIPE, status));
    else if (is_special_char(line, i) == 9)
        i++;
        //ft_lstadd_back_token(lexer, create_token(line + (i++), 1, WHITESPACE, status));
    else if (is_special_char(line, i) > 1 && is_special_char(line, i) < 6)
        i += save_redirection(lexer, line, i, status);
    else if (is_special_char(line, i) == 8)
        i++;
        //ft_lstadd_back_token(lexer, create_token(line + (i++), 1, ENV, status));
    else if (is_special_char(line, i) == 6)
        //ft_lstadd_back_token(lexer, create_token(line + (i++), 1, S_QUOTE, status));
        {i++;
        i += save_squotes(lexer, line + i, status);
        i++;}
    else if (is_special_char(line, i) == 7)
        //ft_lstadd_back_token(lexer, create_token(line + (i++), 1, D_QUOTE, status));
        {i++;
        i += save_dquotes(lexer, line + i, status);
        i++;}
        
    return (i);
}


t_token *read_input(char *line)
{
    int i;
    t_token *lexer;
    enum e_state status;

    i = 0;
    status = DEFAULT;
    lexer = NULL;
    if (is_ascii(line) == FALSE)
    {
        printf("error: invalid characters found");
        // error function
    }
    if (forbidden_series(line) > 0)
    {
        if (forbidden_series(line) == 1)
            {printf("syntax error near unexpected token\n");
            return (NULL);}
            //error function
        else if (forbidden_series(line) == 2)
        {
            printf("tout ce qui n'est pas demande n'est pas a faire\n");
            return (NULL);
        }
    }
    while (line[i])
    {
        status = set_status(status, line, i);
        i = tokenizer(&lexer, line, i, status);
    }
    if_redir(lexer);
    redefine_status(lexer);
    free(line);
    //printf("%s\n", lexer->value);
    return (lexer);
}

void if_redir(t_token *lexer)
{
    while (lexer && lexer->next)
    {
        if (lexer->type == REDIR_IN)
            lexer->next->type = STD_IN;
        else if (lexer->type == REDIR_OUT)
            lexer->next->type = TRUNC;
        else if (lexer->type == DREDIR_OUT)
            lexer->next->type = APPEND;
        else if (lexer->type == HEREDOC)
            lexer->next->type = LIMITER; 
        lexer = lexer->next; 
    }
}

void redefine_status(t_token *lexer)
{
    while (lexer && lexer->next)
    {
        if (lexer->qstatus == DQUOTE && lexer->next->type == D_QUOTE)
            lexer->next->qstatus = DQUOTE;
        else if (lexer->qstatus == SQUOTE && lexer->next->type == S_QUOTE)
            lexer->next->qstatus = SQUOTE;
        lexer = lexer->next;
    }
}
