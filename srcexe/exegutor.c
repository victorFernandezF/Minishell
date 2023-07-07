/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exegutor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:17:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 18:40:37 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*pathbar(char *path, char *cmd);
char	**get_binpath(t_env *env);
int		n_params(char **mat);
char	*fillargmat(char *str);
int		argsize(t_cmd *cmd);

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
		execve(path, arg, senv);
	free(path);
	free_mat(arg);
	free_mat(senv);
	wait(&status);
	return (EXIT_SUCCESS);
}
