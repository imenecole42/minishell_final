#include "minishell.h"

void	msg_error1(char *err)
{
	perror(err);
}
void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
int	ft_no_path(char  **env)
{

	int		i;

	i = 0;
	while ((env[i]) && !ft_strnstr(env[i], "PATH", 4))
		i++;
	return (i);
}

char	**ft_get_path(char  **env)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}
char	*get_cmd(char *cmd, char **envp)
{

	char 	**paths;
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i=ft_no_path(envp);
	if(i == ft_strlen_mat(envp))
	{
		write(2,"No such file or directory",25);
		return(0);
	}
	else
	{
		paths = ft_get_path(envp);
		i = -1;
		while (paths[++i])
		{
			slash = ft_strjoinn(paths[i], "/");
			path = ft_strjoinn(slash, cmd);
			free(slash);
			if (!access(path, F_OK))
			{
				ft_free(paths);
				return (path);
			}
			free(path);
		}
		ft_free(paths);
	}
	return (0);
}