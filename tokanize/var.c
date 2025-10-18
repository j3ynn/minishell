#include "../minishell.h"

char	*env_value(t_heart *heart, char *var_name)	//cerca il valore di una variabile d’ambiente
{
	int		i;
	char	*equal_pos;
	int		name_len;

	i = 0;
	while (heart->env[i])
	{
		equal_pos = ft_strchr(heart->env[i], '=');
		if (equal_pos)
		{
			name_len = equal_pos - heart->env[i];
			if (ft_strncmp(heart->env[i], var_name, name_len) == 0 &&	var_name[name_len] == '\0')
				return (equal_pos + 1);
		}
		i++;
	}
	return (NULL);
}

void	expand_var(char *str, int *i, char *result, int *j, t_heart *heart)	//espande le variabili (sostituendo il nome variabile con il suo valore)
{
	char	name_var[MAX_VAR_LENGTH];
	char	*value;
	int		k = 0;

	(*i)++;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		name_var[k++] = str[*i];
		(*i)++;
	}
	name_var[k] = '\0';
	value = env_value(heart, name_var);	//cercarca la variabile d’ambiente(es: getenv("USER")
	if (value)
	{
		k = 0;
		while (value[k])
		{
			result[(*j)++] = value[k];
			k++;
		}
	}
}	//str = name $USER -> $USER = gayia -> result = name gayia   capito ?
