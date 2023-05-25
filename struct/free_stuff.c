/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/05/25 12:56:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Frees every element of the struct that needs to
 * be freed. and frees the struct itself
 * 
 * @param cmd Struct.
 */
void	free_struct(t_cmd *cmd)
{
	int		i;
	t_cmd	*og;

	og = cmd;
	i = -1;
	free(cmd->cmd);
	if (cmd->flags != NULL)
		free(cmd->flags);
	if (cmd->params != NULL)
		free_array(cmd->params);
	free(cmd->output);
	while (cmd->next != NULL)
	{
		cmd = cmd->next;
		free(cmd->cmd);
		free(cmd->flags);
		free_array(cmd->params);
		free(cmd->output);
		free(cmd);
	}
	cmd = og;
	free(og);
	cmd = NULL;
}

/**
 * @brief Frees every strings inside of an array of strings and
 * frees the array itself.
 * 
 * @param array Array of strings.
 */
void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i] == NULL)
			break ;
		free(array[i]);
	}
	free(array);
	array = NULL;
}
