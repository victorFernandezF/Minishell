/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exegutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:17:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/10 09:59:53 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*pathbar(char *path, char *cmd);
char	**get_binpath(t_env *env);
int		n_params(char **mat);
char	*fillargmat(char *str);
int		argsize(t_cmd *cmd);

void	closeback(t_cmd *cmd)
{
	if (cmd->index < cmd->nb_cmd)
		close(cmd->pipes[cmd->index - 1][1]);
	if (cmd->index > 1)
		close(cmd->pipes[cmd->index - 2][0]);
}

void	exepro(char *path, char **arg, char **senv, t_cmd *cmd)
{
	if (cmd->index > 1)
	{
		close(cmd->pipes[cmd->index - 2][1]);
		dup2(cmd->pipes[cmd->index - 2][0], STDIN_FILENO);
		close(cmd->pipes[cmd->index - 2][0]);
	}
	if (cmd->index < cmd->nb_cmd)
	{
		close(cmd->pipes[cmd->index - 1][0]);
		dup2(cmd->pipes[cmd->index - 1][1], STDOUT_FILENO);
		close(cmd->pipes[cmd->index - 1][1]);
	}
	execve(path, arg, senv);
}

char	**argtomat(t_cmd *cmd)
{
	char	**args;
	int		s;
	int		i;
	int		j;

	s = argsize(cmd);
	args = (char **)malloc((s + 1) * sizeof(char *));
	i = -1;
	while (++i < s)
	{
		j = -1;
		if (i == 0)
			args[i] = fillargmat(cmd->cmd);
		else if (i == 1 && cmd->flags)
			args[i] = fillargmat(cmd->flags);
		else
			args[i] = fillargmat(cmd->params[++j]);
	}
	args[i] = NULL;
	return (args);
}

char	*exepath(char *cmd, t_env *env)
{
	char	**pathvar;
	char	*tmp;
	int		fd;
	int		i;

	i = -1;
	pathvar = get_binpath(env);
	if (!pathvar)
		return (NULL);
	while (pathvar[++i])
	{
		tmp = pathbar(pathvar[i], cmd);
		fd = open(tmp, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			return (tmp);
		}
		free(tmp);
	}
	return (NULL);
}

int	exegutor(t_cmd *cmd, t_env *env)
{
	char	**senv;
	char	**arg;
	char	*path;
	int		pid;
	int		status;

	path = exepath(cmd->cmd, env);
	if (!path)
		return (cmd_error(cmd->cmd, ": No such file or directory", env));
	arg = argtomat(cmd);
	senv = envtomatexp(env);
	pid = fork();
	if (pid == 0)
		exepro(path, arg, senv, cmd);
		//execve(path, arg, senv);
	free(path);
	free_mat(arg);
	free_mat(senv);
	wait(&status);
	closeback(cmd);
	return (EXIT_SUCCESS);
}
