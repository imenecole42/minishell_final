/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:25:11 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/23 18:19:07 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	is_exit(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
		return (0);
	i++;
	while (ft_isdigit(str[i]) != 0)
		i++;
	if (!str[i])
		return (1);
	return (0);
}

 void	ft_many_arg(t_data *mini)
 {
 	
 	write(2, "exit: too many arguments\n", 25);
 	if (mini->argc > 1)
 	{
 		//close_pipe et free childs
 		exit(1);
 	}
 	return ;
 }

 void	ft_exit(t_data *mini, char **cmd)
 {
	int atoi;
 	if (is_exit(cmd[1]) && ft_strlen_mat(cmd) > 2)
 		ft_many_arg(mini);
 	else if (cmd[1] && is_exit(cmd[1]) == 0)
 	{
 		write(2, "exit : ", 8);
 		ft_putstr_fd(cmd[1], 2);
 		write(2, ": numeric argument required\n", 29);
 		//close_pipe et free childs
 		exit(2);
 	}
 	else if (ft_strlen_mat(cmd) == 1)
 	{
 		write(2, "exit\n", 5);
 		//close_pipe et free childs
 		exit(0);
 	}
 	else if (cmd[1] && is_exit(cmd[1]))
 	{	
 		atoi = ft_atoi(cmd[1]);
 		//close_pipe et free childs
 		exit (atoi);
 	}
 }
