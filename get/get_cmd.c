/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/07/11 13:13:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the number of commands.
 * 
 * @param cmd_line command line
 * @return [Int] The number of commands found. 
 */
int	get_nb_cmd(char *cmd_line)
{
	int	i;
	int	cmd;

	i = -1;
	cmd = 1;
	while (cmd_line[++i])
		if (is_pipe(cmd_line[i]) && !is_between_double_quotes(cmd_line, i)
			&& !is_between_simple_quotes(cmd_line, i))
			cmd++;
	return (cmd);
}

/**
 * @brief Splits the name of the command from the command_line.
 * 
 * @param cmd_line Command lime.
 * @return [Char *] The command name. 
 */
char	*get_cmd(char *cmd_line, t_cmd	*cmd)
{
	int		i;
	int		len;
	char	*rest;

	if (ft_strlen(cmd_line) == 0)
		return (NULL);
	i = skip_characters(cmd_line, 0);
	cmd->cmd = ft_substr(cmd_line, 0, i);
	i = skip_whitespaces(cmd_line, i);
	len = strlen_starting_in(cmd_line, i);
	rest = ft_substr(cmd_line, i, len);
	free(cmd_line);
	return (rest);
}
