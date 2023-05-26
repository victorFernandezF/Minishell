/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/05/26 17:33:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the number of commands.
 * 
 * @param cmd_line command line
 * @return The number of commands found. 
 */
int	get_nb_cmd(char *cmd_line)
{
	int	i;
	int	cmd;

	printf("%s\n", cmd_line);
	i = -1;
	cmd = 1;
	while (cmd_line[++i])
		if (is_pipe(cmd_line[i]))
			cmd++;
	return (cmd);
}

/**
 * @brief Splits the name of the command from the command_line.
 * 
 * @param cmd_line Command lime.
 * @return The command name. 
 */
char	*get_cmd(char *cmd_line)
{
	int		i;
	int		j;
	int		len;
	char	*cmd_name;

	i = -1;
	j = 0;
	i = skip_whitespaces(cmd_line, 0);
	len = skip_characters(cmd_line, i);
	cmd_name = malloc((len + 1) * sizeof(char));
	if (!cmd_name)
		return (NULL);
	while (cmd_line[i] != ' ' && cmd_line[i] != '\0')
		cmd_name[j++] = cmd_line[i++];
	cmd_name[j] = '\0';
	return (cmd_name);
}
