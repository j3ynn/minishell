#include "../minishell.h"
// Estrai solo la KEY da "KEY=VALUE"
static char *extract_key(const char *var)
{
    const char *eq = strchr(var, '=');
    if (!eq)
        return NULL;

    size_t key_len = eq - var;
    char *key = malloc(key_len + 1);
    if (!key)
        return NULL;

    strncpy(key, var, key_len);
    key[key_len] = '\0';
    return key;
}

// Aggiorna variabile esistente
static void update_var(char **envp, int index, const char *var)
{
    free(envp[index]);
    envp[index] = strdup(var);
}

// Aggiunge variabile nuova
static char **add_var(char **envp, const char *var)
{
    int count = count_env(envp);
    char **new_env = realloc(envp, sizeof(char *) * (count + 2));
    if (!new_env)
        return envp; // se realloc fallisce, mantieni l'originale

    new_env[count] = strdup(var);
    new_env[count + 1] = NULL;
    return new_env;
}

// Funzione principale export
char **export_env_var(char **envp, const char *var, t_heart *heart)
{
	if (!is_valid_identifier(var))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd((char *)var, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		heart->last_status = 1; // bash restituisce 1
		return envp;
	}
	char *key = extract_key(var);
   	if (!key)
        	return envp; // nessun '=', non faccio nulla

    int index = find_env_index(envp, key);
    free(key);

    if (index != -1)
    {
        update_var(envp, index, var); // aggiorno variabile esistente
        return envp;
    }

    // altrimenti la aggiungo
    return add_var(envp, var);
}
