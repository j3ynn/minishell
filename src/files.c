/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:00:56 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 18:02:31 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_input_file(t_comand *cmd, t_heart *heart)
{
	int	fd;

	if (!cmd->input_file)
		return (-1);
	if (!ft_strcmp(cmd->input_file, "HEREDOC"))
	{
		fd = create_heredoc(heart);
		return (fd);
	}
	fd = open(cmd->input_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(cmd->input_file);
	}
	return (fd);
}

int	open_output_file(t_comand *cmd)
{
	int	flags;
	int	fd;

	if (!cmd || !cmd->output_file)
		return (-1);
	flags = O_WRONLY | O_CREAT;
	if (cmd->redirection)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(cmd->output_file, flags, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(cmd->output_file);
	}
	return (fd);
}
