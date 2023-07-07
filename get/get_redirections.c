/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:08:45 by victofer          #+#    #+#             */
/*   Updated: 2023/07/07 14:11:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_redirections(t_cmd *cmd, t_env *env, char *expanded)
{
	if (cmd->nb_outputs > 0)
		cmd->output = get_output(expanded, cmd, env);
	if (cmd->nb_inputs > 0)
		cmd->input = get_input(expanded, cmd, env);
}
