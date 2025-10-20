#include "../minishell.h"

// Conta le variabili nell'env
int count_env(char **envp) {
    int count = 0;
    while (envp[count])
        count++;
    return count;
}

// Trova indice della variabile con chiave `key`
// Ritorna -1 se non trovata
int find_env_index(char **envp, const char *key) {
    int i = 0;
    size_t key_len = strlen(key);

    while (envp[i]) {
        if (strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
            return i;
        i++;
    }
    return -1;
}

// Sposta indietro tutte le variabili dopo `index`
static void shift_env(char **envp, int index) {
    while (envp[index]) {
        envp[index] = envp[index + 1];
        index++;
    }
}

int is_valid_identifier(const char *str)
{
    int i;

    if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
        return (0);
    i = 1;
    while (str[i] && str[i] != '=')
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

// Funzione principale unset
char **unset_env_var(char **envp, const char *key, t_heart *heart) {
    
	if (!is_valid_identifier(key))
	{
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd((char *)key, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		heart->last_status = 1; // bash restituisce 1 su errore
		return envp;
	}
	int count = count_env(envp);
	int index = find_env_index(envp, key);
	if (index == -1) // non trovata → array invariato
        return envp;
	free(envp[index]);       // libera la stringa da rimuovere
	shift_env(envp, index);  // sposta indietro le altre

    // Ridimensiona l'array (una posizione in meno)
	char **new_env = realloc(envp, sizeof(char *) * count);
	if (!new_env)
		return envp; // se realloc fallisce, mantieni il vecchio

    return new_env;
}

