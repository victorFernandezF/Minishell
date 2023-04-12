/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/04/12 18:20:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_struct(t_cmd *cmd)
{
	(void)cmd;
	free(cmd->cmd);
	free(cmd->flags);
	free(cmd->next);
	free(cmd);
	cmd = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	array = NULL;
}
