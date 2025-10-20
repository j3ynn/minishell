#include "../minishell.h"

volatile sig_atomic_t g_signal = 0;

/**
 * Handler per SIGINT (Ctrl+C) e SIGQUIT (Ctrl+\).
 */
void sigint_handler(int signo)
{
    if (signo == SIGINT)
    {
        g_signal = SIGINT;        // segno che è arrivato SIGINT
        write(1, "\n", 1);        // vai a capo
        rl_on_new_line();         // readline: nuova linea
        rl_replace_line("", 0);   // cancella input corrente
        rl_redisplay();           // ristampa il prompt
    }
    else if (signo == SIGQUIT)
    {
        g_signal = SIGQUIT;       // lo segno, ma non faccio nulla in modalità interattiva
        // Nota: bash in modalità interattiva ignora SIGQUIT
    }
}

/**
 * Inizializza la gestione dei segnali.
 * Va chiamata all'inizio del programma (es. in main).
 */
void setup_signals(void)
{
    signal(SIGINT, sigint_handler);   // Ctrl+C → nuova linea e prompt
    signal(SIGQUIT, sigint_handler);  // Ctrl+\ → ignorato in interactive mode
}

