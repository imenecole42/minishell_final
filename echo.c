/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:55:49 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/20 20:11:38 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *argv)
{
	int	i;

	i = 1;
	if (argv[0] == '-')
	{
		while (argv[i] == 'n')
			i++;
		if (argv[i] == '\0')
			return (1);
	}
	return (0);
}

int	ft_echo(char **argv, t_data *mini)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < mini->cmds->argc && ft_check(argv[i]))
	{
		i++;
		flag = 1;
	}
	while (i < mini->cmds->argc)
	{
		printf("%s",argv[i]);
		if(i + 1 < mini->cmds->argc)
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
