/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:57:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/08 18:42:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	heredoc_detector(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '<' && str[i + 1] == '<' )
			return (1);
	return (0);
}

t_cmd	*heredoc(t_cmd *cmd, char *cmd_line)
{
	char	*delimiter;
	char	*read_here;
	int		heredoc_fd;

	delimiter = get_delimiter(cmd_line);
	heredoc_fd = open("heredoc_tmp", O_CREAT | O_RDWR | O_APPEND, 0644);
	while (1)
	{
		read_here = readline(">");
		write(heredoc_fd, read_here, ft_strlen(read_here));
		write(heredoc_fd, "\n", 1);
		if (are_str_equals(read_here, delimiter))
			break ;
	}
	free(delimiter);
	free(read_here);
	cmd->input = heredoc_fd;
	close(heredoc_fd);
	return (cmd);
}

char	*get_delimiter(char *str)
{
	int		i;
	int		j;
	char	*delimiter;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '<' && str[i + 1] == '<' )
		{
			j = 0;
			i += 2;
			i = skip_whitespaces(str, i);
			while (str[j] && str[j] != ' ')
				j++;
			delimiter = malloc((j + 1) * sizeof(char));
			if (!delimiter)
				return (NULL);
			j = 0;
			while (str[i] && str[i] != ' ')
				delimiter[j++] = str[i++];
			delimiter[j] = '\0';
			return (delimiter);
		}
	}
	return (NULL);
}