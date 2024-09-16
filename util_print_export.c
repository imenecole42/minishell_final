#include "minishell.h"
char *ft_get_add_export(t_data *mini, char *str)
{
	char *var;
	char *temp;
	var = ft_select(str);
	int i;
	i = 0;
	while ((mini->export[i]) && (!ft_strnstr(mini->export[i], var, ft_strlen(var))))
		i++;
	if (mini->export[i] == 0)
	{
		if (!(is_plus(str)))
		{
			temp = ft_strdup(str);
			mini->export[i] = temp;
			printf("\n333\n");
		}
		else if ((is_plus(str)))
		{
			temp = strdup_plus(str);
			mini->export[i] = temp;
			printf("\n444444\n");
		}
	}
	return(mini->export[i]);
}
void realloc_export_be(t_data *mini, char *str)
{
	char *var;
	char *val;
	char *export;
	char *temp;
	int i=0;
	var = ft_select(str);
	val = ft_select1(str);
	while (!ft_strnstr(mini->export[i], var, ft_strlen(var)))
		i++;
	export=mini->export[i];
	if (is_plus(str) && val)
	{
		temp=ft_strjoin(export,val);
		mini->export[i]=temp;
		printf("\n1111\n");
		//printf("%s",mini->export[i]);
	}
	else if (!is_plus(str) && val)
	{
		free(mini->export[i]);
		temp = ft_strdup(str);
		mini->export[i] = temp;
		printf("\n2222\n");
		//printf("%s",mini->export[i]);
	}
	return ;
}
void get_export(t_data *mini,char **argv)
{
	int i;
	i = 0;
	while(mini->export[i]&&(!ft_strnstr(mini->export[i], ft_select(argv[1]), ft_strlen(ft_select(argv[1])))))
		i++;
	if(mini->export[i+1] == 0)
		realloc_export(mini,argv[1]);
	else
		realloc_export_be(mini, argv[1]);
			
}