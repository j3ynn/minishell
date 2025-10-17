#include "../minishell.h"

char	*env_value(char **env, char *var_name)	//cerca il valore di una variabile d’ambiente
{
	int		i;
	char	*equal_pos;
	int		name_len;

	i = 0;
	while (env[i])
	{
		equal_pos = ft_strchr(env[i], '=');
		if (equal_pos)
		{
			name_len = equal_pos - env[i];
			if (ft_strncmp(env[i], var_name, name_len) == 0 &&
				var_name[name_len] == '\0')
				return (equal_pos + 1);
		}
		i++;
	}
	return (NULL);
}

void	expand_var(char *str, int *i, char *result, int *j, char **env)	//espande le variabili (sostituendo il nome variabile con il suo valore)
{
	char	name_var[MAX_VAR_LENGTH];
	char	*value;
	int		k;

	(*i)++;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		name_var[k++] = str[*i];
		(*i)++;
	}
	name_var[k] = '\0';
	value = env_value(env, name_var);	//cercarca la variabile d’ambiente(es: getenv("USER")
	if (value)
	{
		k = 0;
		while (value[k])
		{
			result[(*j)++] = value[k];
			k ++;
		}
	}
}	//str = name $USER -> $USER = gayia -> result = name gayia   capito ?