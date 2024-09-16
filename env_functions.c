/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:46:55 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/12 15:50:29 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "Libft/libft.h"

/*void    push_cells(t_env **head_list, char *value)
{
	t_env *tmp;
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
	if(!new_node)
		return ;
	new_node->content = value;
    new_node->next = NULL;
	if (!*head_list)
		(*head_list) = new_node;
	else
    {
        tmp = (*head_list);
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

void	print_lists(t_env *list)
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
	list = NULL;
	while (env[i])
	{
		push_cells(&list, env[i++]);
	}
	print_lists(list);
}
*/