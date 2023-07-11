/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/07/11 12:51:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief creates an array of strings with the parameters found
 *	in the command line given by user.
 * 
 * @param cmd_line Command line
 * @return [Char **] An array of strings with every parameters found. 
 */
char	*get_parameters(char *cmd_line, t_cmd *cmd, t_env *env)
{
	char	**parameters;

	(void)env;
	parameters = ft_split_minishell(cmd_line, 0);
	cmd->params = parameters;
	return (cmd_line);
}
