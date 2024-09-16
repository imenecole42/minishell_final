/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:23:59 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/03 15:24:02 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var(char *var, char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(var, env[i], ft_strlen(var)) != 0)
	{
		i++;
	}
	return (i);
}

int	strjoint_env(char *var, char *path, t_data *mini)
{
	int	i;

	i = get_var(var, mini->env);
	free(mini->env[i]);
	mini->env[i] = ft_strjoin(var, path);
	return (0);
}

char	*get_home(char *var, t_data *mini)
{
	int	i;

	i = get_var(var, mini->env);
	if (i == ft_strlen_mat(mini->env))
		return (NULL);
	return (&mini->env[i][5]);
}

int	cd_new_path(char **cmd, int i, t_data *mini, char *newpath)
{
	if (i == 1 || (cmd[1] && cmd[1][0] == '~' && !cmd[1]))
	{
		newpath = get_home("HOME=", mini);
		if (chdir(newpath) != 0)
			return (write(2, "cd : HOME not set\n", 19), 0);
		return (0);
	}
	if (i > 2)
	{
		return (write(2, "cd: too many arguments\n", 24), 0);
	}
	return (1);
}

int	ft_cd(char **cmd, int argc, t_data *mini)
{
	char	*path;
	char	*newpath;

	path = NULL;
	newpath = NULL;
	if (!cd_new_path(cmd, ft_strlen_mat(cmd), mini, newpath))
		return (0);
	path = getcwd(path, 0);
	if (!path)
		return (write(2, "No such file or directory\n", 27), 1);
	strjoint_env("OLDPWD=", path, mini);
	if (cmd[1][0] != '/')
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, cmd[argc]);
		if (chdir(path) != 0)
			return (free(path), write(2, "cd: ", 5), ft_putstr_fd(cmd[argc], 2) \
			, write (2, " No such file or directory\n", 28), 1);
	}
	else if (chdir(cmd[1]) != 0)
		return (write(2, "cd: ", 5), ft_putstr_fd(cmd[argc], 2) \
		, write (2, " No such file or directory\n", 28), 1);
	newpath = getcwd(newpath, 0);
	strjoint_env("PWD=", newpath, mini);
	return (free(path), free(newpath), 0);
}
