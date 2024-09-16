#include "minishell.h"

int is_plus(char *str)
{
    if(ft_strchr(str,'+'))
        return(1);
    return(0);
}
int is_export(char *str)
{
	int i=0;
	if((str[i]>='a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
		return(1);
	return(0);
}

char *strdup_plus(char *str)
{
    int i;
    int j;
	char *dest;

	j=0;
    i = 0;
    dest=malloc(sizeof(char)*ft_strlen(str)+1);
    while(str[j] && str[j]!='+')
    {
        dest[i]=str[j];
        i++;
        j++;
    }
    if(str[j]=='+')
    {
        j++;
        while(str[j])
        {
            dest[i]=str[j];
            i++;
            j++;
        }
    }
    dest[i]=0;
    return(dest);
}
char *ft_select2(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    while (str && str[i] && str[i] != '=')
        i++;
    dest = (char *) malloc(sizeof(char) *(i + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (str[i] && str[i]!='+' && str[i] != '=')
    {
        dest[j] = str[i];
        j++;
        i++;
    }
    dest[j]='\0';
    return (dest);
}

char *ft_select(char *str)
{
    char    *dest;
    int        i;
    int        j;

    i = 0;
    j = 0;
    while (str && str[i] && str[i] != '=')
        i++;
    if (str[i] == '=')
        dest = (char *) malloc(sizeof(char) * (i + 2));
    else if (str[i] == '\0')
        dest = (char *) malloc(sizeof(char) *(i + 1));
    if (!dest)
        return (NULL);
    while (str[j] && str[j] != '=' && str[j]!='+')
    {
        dest[j] = str[j];
        j++;
    }
    
    if(str[j]=='+' && str[j+1]=='=')
    {
      dest[j++]='=';
      dest[j--]='\0';
    }
    else if (str[j] == '=')
    {
        dest[j++] = '=';
        dest[j] = '\0';
    }
    else
      dest[j]='\0';
    return (dest);
}

char	*ft_select1(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return(0);
	if(str[i]=='=')
      dest = (char *)malloc(sizeof(char) * (strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	while (str && str[i])
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
