/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 19:01:43 by victofer         ###   ########.fr       */
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
 * @return The command name. 
 */
char	*get_cmd(char *cmd_line)
{
	int		i;
	int		len;
	char	*cmd_name;
	char	**temp_array;

	i = -1;
	if (ft_strlen(cmd_line) == 0)
		return (NULL);
	temp_array = ft_split_minishell(cmd_line, 0);
	len = ft_strlen(temp_array[0]);
	cmd_name = malloc((len * sizeof(char)));
	if (!cmd_name)
		return (NULL);
	if (temp_array[0][0] == '>' || temp_array[0][0] == '<')
		return (NULL);
	while (temp_array[0][++i])
		cmd_name[i] = temp_array[0][i];
	cmd_name[i] = '\0';
	free_array(temp_array);
	return (cmd_name);
}
