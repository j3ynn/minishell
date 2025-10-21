/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:35:17 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/21 15:52:23 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>

#define MAX_VAR_LENGTH 256

typedef struct s_heart  t_heart;
extern volatile sig_atomic_t g_signal; // salva lo stato di uscita dell’ultimo comando

	typedef struct s_comand
	{
		t_heart	*heart;			// Puntatore alla struttura principale
		char	*comd;			// Nome del comando ("echo", "ls"...)
		char	**args;			// Array di argomenti ["echo", "hello", NULL]
		char	*input_file;	// File di input o "PIPE_IN"
		char	*output_file;	// File di output o "PIPE_OUT"
		bool	redirection;	// false = >, true = >>
		int		num_arg;		// Numero di argomenti
	} t_comand;

	typedef struct s_heredoc
	{
		char	delimiter[250];	// Delimitatore per heredoc
	} t_heredoc;

	typedef struct s_heart
	{
		t_heredoc	heredoc;		// Gestione heredoc
		t_comand	*comds;			// Array di comandi da eseguire
		char		*input_line;	// Linea di input dell'utente(quella che leggi)
		char		**env;			// Variabili d'ambiente per trovare i comandi
		int			num_comds;		// Numero di comandi (separati da pipe)
		int			**pipes;		// Matrix per le pipe (per collegare i comandi)
		bool		has_pipes;		// se ci sono o no pipe (true ci sono)
		int			stdin_backup;	// Salva lo standard input (tastiera)
		int			stdout_backup;	// Salva lo standard output (schermo)
		int			last_status;
	} t_heart;

void	init_heart(t_heart *heart, char **envp);
void	init_heredoc(t_heart *heart);
void	init_pipes(t_heart *heart);
void	init_stdin_stdout(t_heart *heart);
void	init_comand(t_heart *heart, int num_commands);
void	free_single_command(t_comand *cmd);
void	free_commands(t_heart *heart);
void	free_tokens(char **tokens);
void	handle_redirections(t_comand *cmd, char **tokens, int *j, t_heart *heart);
void	setup_command(t_comand *cmd, char **tokens, t_heart *heart);
void	create_single_command(t_heart *heart, char *cmd_str, int cmd_index);
void	run_builtin_child(t_comand *cmd, t_heart *heart);
void	run_builtin_parent(t_comand *cmd, t_heart *heart);
void	close_all_pipes_child(t_heart *heart);
void	free_pipes(t_heart *heart);
void	init_pipes(t_heart *heart);
void	free_tokens(char **tokens);
void	expand_var(char *str, int *i, char *result, int *j, t_heart *heart);
void	single_quote(char *str, int *i, char *result, int *j);
void	double_quote(char *str, int *i, char *result, int *j, t_heart *heart);
void	free_all(t_heart *heart);
void	free_env(char **env);
void	sigint_handler(int signo);
void	setup_signals(void);

char	**init_envp(char **envp);
char	**add_token(char **tokens, const char *token);
char	*get_word(char *str, int start);
char	**process_input(char *input);
char	**pipes_split(char *input, int num_cmds);
char	*get_path(char *cmd, char **env);
char	*quote_menage(char *token, t_heart *heart);
char	*env_value(t_heart *heart, char *var_name);
char	**unset_env_var(char **envp, const char *key, t_heart *heart);
char	**export_env_var(char **envp, const char *var, t_heart *heart);

int		arraylen(char **array);
int		count_pipes(char *str);
int		count_args(char **tokens);
int		ft_strcmp(const char *s1, const char *s2);
int		handle_quotes(char *str);
int		skip_whitespace(char *str);
int		get_quoted_len(char *str, int start);
int		get_operator_len(char *str, int start);
int		get_normal_len(char *str, int start);
int		get_manage(char *str, int start);
int		redirection(char *token);
int		parse_input(t_heart *heart, char *input);
int		execute_commands(t_heart *heart);
int		create_heredoc(t_heart *heart);
int		is_parent_builtin(const char *cmd);
int		open_output_file(t_comand *cmd);
int		open_input_file(t_comand *cmd, t_heart *heart);
int		is_child_builtin(const char *cmd);
int		count_env(char **envp);
int		find_env_index(char **envp, const char *key);
int		wait_all(pid_t *pids, int n);
int		is_valid_identifier(const char *str);

#endif
