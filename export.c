/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:13:44 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/24 09:20:40 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	realloc_env_be(t_data *mini, char *str)
{
	char	*var;
	char	*val;
	char	*temp;
	int		i;

	i = 0;
	var = ft_select(str);
	val = ft_select1(str);
	while (!ft_strcmp(ft_select(mini->env[i]), var))
		i++;
	printf("i egal==%d",i);
	if (is_plus(str))
	{
		temp = ft_strjoin(mini->env[i], val);
		printf("je strjoin avec +");
		mini->env[i] = temp;
	}
	else if (!is_plus(str))
	{
		free(mini->env[i]);
		printf("je malloc une ligne");
		temp = strdup(str);
		mini->env[i] = temp;
	}
	return ;
}

char	*ft_get_add_env(t_data *mini, char *str)
{
	char	*val;
	char	*temp;
	int		i;

	val = ft_select1(str);
	i = ft_strlen_mat(mini->env);
	
	if (val && !is_plus(str))
	{
		temp = ft_strdup(str);
		mini->env[i] = temp;
	}
	else if (val && is_plus(str))
	{
			temp = strdup_plus(str);
			mini->env[i] = temp;
	}
	return (mini->env[i]);
}

void	get_env(t_data *mini, char **argv)
{
	int	i;

	i = 0;
	while (mini->env[i] && (ft_strcmp(ft_select(mini->env[i]), ft_select(argv[1]))))
		i++;
	printf("%d",i);
	printf("%d",ft_strlen_mat(mini->env));
	if (i == ft_strlen_mat(mini->env))
	{
		realloc_env(mini, argv[1]);
		printf("je rajoute une ligne");
	}
	else
	{
		realloc_env_be(mini, argv[1]);
		printf("je strjoint une ligne");
	}
}

void	ft_export(char **argv, t_data *mini)
{
	if (mini->cmds->argc == 1)
	{
		print_export(mini);
		printf("je suis dans export");
	}
	if (mini->cmds->argc == 2)
	{
		if (is_export(argv[1]) && ft_select1(argv[1]))
		{
			get_env(mini, argv);
			get_export(mini, argv);
		}
		else if (is_export(argv[1]) && !ft_select1(argv[1]))
			get_export(mini, argv);
		else
		{
			write(2, "export: `", 10);
			ft_putstr_fd(argv[1], 2);
			write(2, "': not a valid identifier\n", 27);
		}
	}
	return ;
}
