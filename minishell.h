/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:35:17 by jbellucc          #+#    #+#             */
/*   Updated: 2025/08/06 19:13:07 by jbellucc         ###   ########.fr       */
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

typedef struct s_heart  t_heart;
extern int g_exit; // salva lo stato di uscita dell’ultimo comando

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
	char	*content;		// Contenuto del heredoc
	char	*temp_file;		// File temporaneo
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
} t_heart;

void	init_heart(t_heart *heart, char **envp);
char **init_envp(char **envp);
int arraylen(char **array);
#endif
