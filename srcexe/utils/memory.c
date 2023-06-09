/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:25:25 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 20:34:31 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_pipes(int **pipes, t_cmd *cmd)
{
	int	i;

	i = cmd->nb_cmd - 1;
	while (--i >= 0)
		free(pipes[i]);
	free(pipes);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	while (i >= 0)
	{
		free(mat[i]);
		i--;
	}
	free(mat);
}
