/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:30:17 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/20 13:31:21 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_fd(t_cmd *pipex)
{
	if (pipex->fd_in > 2)
		close(pipex->fd_in);
	if (pipex->fd_out > 2)
		close(pipex->fd_out);
}

void	ft_close(t_cmd *pipex)
{
	int	i;

	i = -1;
	while ((pipex->pfd[++i]))
	{
		if (pipex->pfd[i][0] > 2)
			close(pipex->pfd[i][0]);
		if (pipex->pfd[i][1] > 2)
			close(pipex->pfd[i][1]);
	}
	if (pipex->fd_in > 2)
		close(pipex->fd_in);
	if (pipex->fd_out > 2)
		close(pipex->fd_out);
}

void	close_fd(t_cmd *pipex)
{
	ft_close(pipex);
	free_pfd(pipex);
	free(pipex->pid);
	exit(127);
}
