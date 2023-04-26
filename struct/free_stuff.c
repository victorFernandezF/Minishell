/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/04/26 10:15:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * free_struct
 * ----------------------------
 *	Frees the struct and all its elements.
 */
void	free_struct(t_cmd *cmd)
{
	int		i;
	t_cmd	*og;

	og = cmd;
	i = -1;
	free(cmd->cmd);
	free(cmd->flags);
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

/* 
 * free_array
 * ----------------------------
 *	Frees an array of ints and all its elements.
 */
void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	array = NULL;
}
