/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bullting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:31:19 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/19 16:08:32 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 int	is_builtin(t_data *mini, char **argv)
 {
 	if (!argv[0])
 		return (-1);
 	//g_exit_code = 0;
 	if (ft_strcmp(argv[0], "exit") == 0)
 		return (ft_exit(mini, argv), 1);
 	else if (ft_strcmp(argv[0], "pwd") == 0 )
 		return (ft_pwd(mini));
 	else if (ft_strcmp(argv[0], "cd") == 0)
 	{
 		//if (ft_cd(argv, 1, mini) == 1)
 			//g_exit_code = 1;
 		return (ft_cd(argv, 1, mini));
 	}
 	else if (ft_strcmp(argv[0], "echo") == 0)
 		return (ft_echo(argv, mini));
 	else if (ft_strcmp(argv[0], "export") == 0)
 		return (ft_export(argv, mini),1);
 	if (ft_strcmp(argv[0], "unset") == 0)
 		return (ft_unset(mini, argv[0]),1);
 	if (ft_strcmp(argv[0], "env") == 0 && !argv[1])
 		return (ft_env(mini));
 	return (-1);
 }

 int	builtin_env(char **argv)
 {
 	if (!argv[0])
 		return (-1);
 	if (ft_strcmp(argv[0], "cd") == 0)
 		return (1);
 	if (ft_strcmp(argv[0], "export") == 0)
 		return (1);
 	if (ft_strcmp(argv[0], "unset") == 0)
 		return (1);
 	if (ft_strcmp(argv[0], "exit") == 0)
 		return (1);
 	return (0);
 }
