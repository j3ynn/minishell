/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:47:39 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 18:00:35 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*extract_key(const char *var)
{
	char		*key;
	const char	*eq;
	size_t		key_len;

	key_len = eq - var;
	eq = strchr(var, '=');
	if (!eq)
		return (NULL);
	key = malloc(key_len + 1);
	if (!key)
		return (NULL);
	strncpy(key, var, key_len);
	key[key_len] = '\0';
	return (key);
}

static void	update_var(char **envp, int index, const char *var)
{
	free(envp[index]);
	envp[index] = strdup(var);
}

static char	**add_var(char **envp, const char *var)
{
	int		count;
	char	**new_env;

	count = count_env(envp);
	new_env = realloc(envp, sizeof(char *) * (count + 2));
	if (!new_env)
		return (envp);
	new_env[count] = strdup(var);
	new_env[count + 1] = NULL;
	return (new_env);
}

char	**export_env_var(char **envp, const char *var, t_heart *heart)
{
	int		index;
	char	*key;

	index = find_env_index(envp, key);
	key = extract_key(var);
	if (!key)
		return (envp);
	if (!is_valid_identifier(var))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd((char *)var, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		heart->last_status = 1;
		return (envp);
	}
	free(key);
	if (index != -1)
	{
		update_var(envp, index, var);
		return (envp);
	}
	return (add_var(envp, var));
}
