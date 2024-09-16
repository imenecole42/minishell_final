/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:32:08 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/23 18:39:39 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_exeve(t_cmd *pipex)
{
	ft_free(pipex->cmd);
	free(pipex->pid);
	free_pfd(pipex);
	exit(127);
}

void	ft_dup(int src, int dest)
{
	dup2(src, 1);
	dup2(dest, 0);
}

void	child1(t_cmd *pipex)
{
	if (pipex -> fd_in < 0)
		return (close_fd(pipex));
	ft_dup(pipex -> pfd[pipex->i][1], pipex->fd_in);
	ft_close(pipex);
}

void	child2(t_cmd *pipex)
{
	if (pipex -> fd_out < 0)
		return (close_fd(pipex));
	ft_dup(pipex->fd_out,
		pipex->pfd[pipex->i - 1][0]);
	ft_close(pipex);
}

void	child(t_cmd *pipex, char **envp)
{
	while(pipex != NULL)
	{
		/*if(pipex->cmd[0] && builtin_env(pipex->cmd))
		{
			is_builtin(mini,pipex->cmd);
			free_exeve(pipex);		
		}*/
		if (pipex->cmd[0] && /*!builtin_env(pipex->cmd) &&*/ get_cmd(pipex->cmd[0], envp))
		{
			execve(get_cmd(pipex->cmd[0], envp), pipex->cmd, envp);
			free_exeve(pipex);
		}
		else
		{
			ft_putstr_fd(pipex->cmd[0], 2);
			write(2, ": command not found\n", 20);
			free_exeve(pipex);
		}
		pipex = pipex->next;
		
	}		
}
