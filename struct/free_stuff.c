/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/02 12:21:20 by victofer         ###   ########.fr       */
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
	t_cmd	*og;

	og = cmd;
	free(cmd->cmd);
	free(cmd->flags);
	if (cmd->params != NULL)
		free_array(cmd->params);
	while (cmd->next != NULL)
	{
		cmd = cmd->next;
		free(cmd->cmd);
		free(cmd->flags);
		free_array(cmd->params);
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

void	free_parser(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}