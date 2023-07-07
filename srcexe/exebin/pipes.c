/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:47:11 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 19:49:31 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	modfds(int	**pipes, t_cmd *cmd)
{
	cmd->pipes = pipes;
	if (cmd->index > 1 && cmd->input == 0)
		cmd->input = pipes[cmd->index - 2][0];
	if (cmd->index < cmd->nb_cmd && cmd->output == 0)
		cmd->output = pipes[cmd->index - 1][1];
}

int	**spipes(t_cmd *cmd)
{
	int	i;
	int	**pipes;

	pipes = (int **)malloc((cmd->nb_cmd - 1) * sizeof(int *));
	i = -1;
	while (++i < cmd->nb_cmd - 1)
	{
		pipes[i] = (int *)malloc(2 * sizeof(int));
		pipe(pipes[i]);
	}
	return (pipes);
}
