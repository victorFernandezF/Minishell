/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:44 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/12 22:04:05 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		exegutor(t_cmd *cmd, t_env *env);
int		**spipes(t_cmd *cmd);
void	modfds(int	**pipes, t_cmd *cmd);
void	free_pipes(int **pipes, t_cmd *cmd);
void	closeback(t_cmd *cmd);

int	check_bi(t_cmd *cmd, t_env *env)
{
	if (!(ft_strncmp((cmd->cmd), "cd", 3)))
		return (ft_cd(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "echo", 5)))
		return (ft_echo(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "env", 4)))
		return (ft_env(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "export", 7)))
		return (ft_export(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "pwd", 4)))
		return (ft_pwd(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "unset", 6)))
		return (ft_unset(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "exit", 5)))
		return (ft_exit(cmd, env));
	else
		return (2);
}

void	processing(t_cmd *cmd, t_env *env)
{
	int		**pipes;
	t_cmd	*tmp;

	tmp = cmd;
	if (cmd->nb_cmd == 1)
	{
		if (check_bi(cmd, env) == 2)
			exegutor(cmd, env);
	}
	else
	{
		pipes = spipes(cmd);
		while (cmd)
		{
			modfds(pipes, cmd);
			if (check_bi(cmd, env) == 2)
				exegutor(cmd, env);
			cmd = cmd->next;
		}
		free_pipes(pipes, tmp);
	}
	free_struct(tmp);
}
