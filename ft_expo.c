

#include "minishell.h"

char *get_var_echo(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    int start;
    int end;
    if(str[i]=='$')
      i++;
    start = i;
    while(str[i] && ft_isalnum_mini(str[i]))
        i++;
    end = i;
    dest = (char *) malloc(sizeof(char) * ((end - start) + 1));
    if (!dest)
        return (NULL);
    while (start<end && ft_isalnum_mini(str[start]))
    {
        dest[j] = str[start];
        j++;
        start++;
    }
    dest[j]='\0';
    return (dest);
}

char *get_val_echo(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    if(str[i]=='$')
      i++;
    while(str[i] && ft_isalnum_mini(str[i]))
        i++;
    if (!str[i + 1])
        return(0);
    dest = (char *) malloc(sizeof(char) * (ft_strlen(str)- i + 1));
    if (!dest)
        return (NULL);
    while (str[i])
    {
        dest[j] = str[i];
        j++;
        i++;
    }
    dest[j]='\0';
    return (dest);
}

char *get_val_echo_space(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    if(str[i]=='$')
      i++;
    while(str[i] && ft_isalnum_mini(str[i]))
        i++;
    if (!str[i + 1])
        return(0);
    dest = (char *) malloc(sizeof(char) * (ft_strlen(str)- i + 1));
    if (!dest)
        return (NULL);
    while(str[i]==32)
        i++;
    while (str[i])
    {
        dest[j] = str[i];
        j++;
        i++;
    }
    dest[j]='\0';
    return (dest);
}

char *check_var(char *str,t_data *mini)
{
    int i = 0;
    while ((mini->env[i]) && ft_strcmp(ft_select2(mini->env[i]), get_var_echo(str)))
			i++;
	if (mini->env[i] == 0)
		return(NULL);
    else 
        return(mini->env[i]);
}

int ft_print_var_quote(char *str,t_data *mini)
{
	if(check_var(str,mini) != 0)
	{
		printf("%s",ft_select1(check_var(str,mini)));
		printf("%s\n",get_val_echo(str));
	}
	else
		printf("%s\n",get_val_echo(str));
    return(0);
}

int ft_print_var_sans_quote(char *str,t_data *mini)
{
	if(check_var(str,mini) != 0)
	{
		printf("%s",ft_select1(check_var(str,mini)));
		printf("%s\n",get_val_echo(str));
	}
	else
		printf("%s\n",get_val_echo_space(str));
    return(0);
}
void print_simple(char *str)
{
    printf("%s\n",str);
}
