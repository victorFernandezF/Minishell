/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:14:41 by victofer          #+#    #+#             */
/*   Updated: 2023/04/24 18:24:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_struct(t_cmd *cmd)
{
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = NULL;
	cmd->flags = NULL;
	cmd->params = NULL;
	cmd->input = 0;
	cmd->nb_outputs = 0;
	cmd->output = NULL;
	cmd->index = 1;
	return (cmd);
}
