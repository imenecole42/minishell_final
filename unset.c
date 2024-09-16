/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:06 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/06 11:27:59 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_data *mini, char *str)
{
	int	i;

	i = 0;
	if (mini->argc > 1)
	{
		while ((mini->env[i]) && ft_strcmp(ft_select2(mini->env[i]), str))
			i++;
		if (mini->env[i + 1] == 0)
			return ;
		else
			realloc_unset(mini, str);
	}
	return ;
}

void	util_unset(t_data *mini, int i, int j, char **temp)
{
	while (mini->env[i])
	{
		temp[j] = mini->env[i];
		j++;
		i++;
	}
	free(mini->env);
	mini->env = temp;
}

void	realloc_unset(t_data *mini, char *str)
{
	int		i;
	int		j;
	int		u;
	char	**temp;

	i = 0;
	j = 0;
	u = 0;
	temp = malloc(sizeof(char *) * (ft_strlen_mat(mini->env)));
	if (!temp)
		return ;
	temp[ft_strlen_mat(mini->env) - 1] = 0;
	while ((mini->env[u]) && ft_strcmp(ft_select2(mini->env[u]), str))
			u++;
	while (i < u)
	{
		temp[j] = mini->env[i];
		j++;
		i++;
	}
	i++;
	util_unset(mini, i, j, temp);
}
