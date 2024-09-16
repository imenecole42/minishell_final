#include "minishell.h"
void	free_pfd(t_cmd *pipex)
{
	int	i;

	i = 0;
	while (i < pipex -> nbr_pipe)
	{
		free(pipex -> pfd[i]);
		i++;
	}
	free(pipex -> pfd);
}

int	ft_free_pipes(t_cmd *pipex, int n)
{
	int	i;

	i = -1;
	if (pipex -> pfd)
	{
		while (pipex -> pfd[++i] && i < n)
			free_pfd(pipex);
		free_pfd(pipex);
	}
	return (0);
}

void	creat_pipes(t_cmd *pipex)
{
	int	i;

	i = -1;
	pipex->pfd = (int **)malloc(sizeof(int *) * (pipex->nbr_pipe + 1));
	if (!pipex->pfd)
		msg_error(ERR_PIPE);
	while (++i < pipex->nbr_pipe)
	{
		pipex->pfd[i] = (int *)malloc(sizeof(int) * (2));
		if ((!pipex->pfd[i]) || pipe(pipex->pfd[i]))
		{
			ft_free_pipes(pipex, i);
			msg_error(ERR_PIPE);
		}
	}
	pipex->pfd[pipex->nbr_pipe] = 0;
}