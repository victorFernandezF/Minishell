/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/07/13 12:43:11 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Splits the params of the command from the command_line
 * and store them in the struct.
 * 
 * @param cmd_line Command lime.
 * @return [Char *] The given line.
 */
char	*get_parameters(char *cmd_line, t_cmd *cmd, t_env *env)
{
	char	**parameters;

	(void)env;
	parameters = ft_split_minishell(cmd_line, 0);
	cmd->params = parameters;
	return (cmd_line);
}
