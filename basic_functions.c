/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:45:41 by hferjani          #+#    #+#             */
/*   Updated: 2023/01/17 12:02:09 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

t_env *push_cell(t_env *list, char *data, int pos)
{
	int i;
	t_env *tmp;
	t_env *new_node;

	tmp = list;
	new_node = malloc(sizeof(t_env));
	if(!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = data;
	if (!list)
		return (new_node);
	i = 0;
	while (i < pos)
	{
		i++;
		tmp = tmp->next;
	}
	new_node->next = tmp;
	return (list);
}

void	print_list(t_env *list)
{
  int		i;

  i = 0;
  while (list)
  {
  	printf("-----------------------------------\n");
  	printf("| i = %d                            \n", i);
  	printf("| list->data : %s            \n", list->content);
  	printf("-----------------------------------\n");
  	list = list->next;
  	i++;
  }
}

void	display_env(char **env)
{
	int	i;
	t_env *list;

	i = 0;
	while (env[i])
	{
		list = push_cell(list, env[i], i);
		i++;
	}
	//print_list(list);
}

int	is_even(int num)
{
	return !(num & 1);
}

int	ft_quotes(char *s)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			count++;
		i++;
	}
	if(is_even(count))
	{
		return(1);
		printf("The number is even.");
	}
	return(0);
}

