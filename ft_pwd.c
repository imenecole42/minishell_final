/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:38 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/03 15:43:16 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_data *mini)
{
	char	*pwd;

	pwd = NULL;
	if (mini->argc == 2)
	{
		pwd = getcwd(NULL, 0);
		if (!pwd)
		{
			write(2, "pwd: error retrieving current directory: getcwd: \
			cannot access parent directories: No such file or directory\n", 112);
			return (1);
		}
		else
		{
			printf("%s\n", pwd);
		}
	}
	else
		write(2, "pwd: too many arguments\n", 25);
	return (0);
}
