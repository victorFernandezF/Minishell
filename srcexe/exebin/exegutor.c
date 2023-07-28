/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exegutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:17:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/28 10:22:21 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	signal_handler_child(int sig);
char	*pathbar(char *path, char *cmd);
char	**get_binpath(t_env *env);
int		n_params(char **mat);
char	*fillargmat(char *str);
int		argsize(t_cmd *cmd);

void	wstatus(int status, t_env *env)
{
	char	*tmp;
	int		e;

	e = WEXITSTATUS(status);
	tmp = ft_itoa(e);
	set_env(env, "?", tmp);
	free(tmp);
}

void	exepro(char *path, char **arg, char **senv, t_cmd *cmd)
{
	signal(SIGINT, signal_handler_child);
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
	if (cmd->index == 1 && cmd->input != 0)
		dup2(cmd->input, STDIN_FILENO);
	if (cmd->index == cmd->nb_cmd && cmd->output != 0)
		dup2(cmd->output, STDOUT_FILENO);
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
	j = -1;
	while (++i < s)
	{
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
	fd = open(cmd, O_RDONLY);
	if (fd > 0)
		return (cmd);
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
		return (cmd_error(cmd->cmd, ": command not found", env));
	arg = argtomat(cmd);
	senv = envtomatexecve(env, cmd->cmd);
	pid = fork();
	if (pid == 0)
		exepro(path, arg, senv, cmd);
	if ((ft_strncmp(path, cmd->cmd, ft_strlen(cmd->cmd))))
		free(path);
	free_mat(arg);
	free_mat(senv);
	wait(&status);
	wstatus(status, env);
	closeback(cmd);
	return (EXIT_SUCCESS);
}
