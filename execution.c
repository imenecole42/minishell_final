/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:22:00 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/24 08:56:00 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_cmd *exec, t_data *mini)
{
	if (exec->nbr_cmd == 1)
	{
		//if (builtin_env(exec->cmd) == 1)
			//is_builtin(mini, exec->cmd);
		//else
			printf("nbr de commande egal 1");
			exec_one_cmd(exec, mini);
			
	}
	else
		exec_pipe(exec,mini);
}

void	exec_one_cmd(t_cmd *exec, t_data *mini)
{
	exec->pid_one = fork();
	if (exec->pid_one == -1)
		return (write(2, "Error Fork\n", 12), free(NULL));
	else if (exec -> pid_one == 0)
	{
		if (exec->cmd[0] && get_cmd(exec->cmd[0], mini->env))
		{
			execve(get_cmd(exec->cmd[0], mini->env), exec->cmd, mini->env);
			ft_free(exec->cmd);
			exit(127);
		}
		else
		{
			ft_putstr_fd(exec->cmd[0], 2);
			write(2, ": command not found\n", 20);
			ft_free(exec->cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(exec->pid_one, 0, 0);
		ft_close_fd(exec);
	}
}

void	fork_pipe(t_cmd *pipex, t_data *mini)
{
	pipex -> pid[pipex -> i] = fork();
	if (pipex -> pid[pipex -> i] == -1)
		return (write(2, "Error Fork\n", 12), free(NULL));
	if (pipex -> pid[pipex -> i] == 0)
	{
		if (pipex ->i == 0)
			child1(pipex);
		else if (pipex -> i == pipex->nbr_cmd - 1)
			child2(pipex);
		else
		{
			ft_dup(pipex -> pfd[pipex -> i][1],
				pipex -> pfd[pipex -> i - 1][0]);
			ft_close(pipex);
		}
		child(pipex, mini->env);
	}
}

void	exec_pipe(t_cmd *pipex,t_data *mini)
{
	pipex->pid = (int *)malloc(sizeof(int) * (pipex->nbr_cmd));
	if (!pipex->pid)
		msg_error(ERR_PIPE);
	creat_pipes(pipex);
	pipex->i = -1;
	while (++(pipex->i) < pipex->nbr_cmd)
		fork_pipe(pipex, mini);
	pipex->i = 0;
	while (pipex->i < pipex->nbr_cmd)
	{
		ft_close(pipex);
		waitpid(pipex->pid[pipex->i], NULL, 0);
		pipex->i++;
	}
	free(pipex->pid);
	free_pfd(pipex);
}
