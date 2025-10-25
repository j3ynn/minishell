/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:02:56 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 18:06:33 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	create_heredoc2(int fd, t_heart *heart)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("warning: here-document delimited by end-of-file\n",
				2);
			break ;
		}
		if (ft_strcmp(line, heart->heredoc.delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	return (0);
}

int	create_heredoc(t_heart *heart)
{
	int	fd;

	fd = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("heredoc");
		return (-1);
	}
	create_heredoc2(fd, heart);
	close(fd);
	fd = open(".heredoc_tmp", O_RDONLY);
	if (fd == -1)
	{
		perror("heredoc");
		return (-1);
	}
	unlink(".heredoc_tmp");
	return (fd);
}
