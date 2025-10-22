#include "../minishell.h"

// Cerca la variabile PATH dentro envp
static char	*find_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

// Costruisce il path completo e verifica se è eseguibile
static char	*check_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

// Restituisce il path assoluto di un comando (es. "ls" -> "/bin/ls")
char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;
	
	// Caso 1: contiene '/' → è un percorso (assoluto o relativo)
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));  // restituisci una copia
		else
			return (NULL);            // non eseguibile / non trovato
	}

	// Caso 2: nessuno slash → cerca in PATH
	path_env = find_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = check_path(paths[i], cmd);
		if (full_path)
		{
			free_tokens(paths);
			return (full_path);
		}
		i++;
	}
	free_tokens(paths);
	return (NULL);
}

int wait_all(pid_t *pids, int n)
{
	int i;
	int status;
	int exit_code = 0;
	i = 0;
	while (i < n)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
		i++;
	}
	return exit_code; // restituisce l'exit code dell'ultimo processo
}
