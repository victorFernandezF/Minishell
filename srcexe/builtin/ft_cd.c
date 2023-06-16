/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- < fortega-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/16 22:09:16 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cd_go(t_env *env, char *dir)
{
	char	*tmp;
	char	s[100];

	printf("%p\n", env);
	printf("dir: %s\n", dir);
	printf("pwd: %s\n", getcwd(s, 100));
	if (chdir(dir) != 0)
	{
		tmp = ft_strjoin(dir, ": No such file or directory");
		free(dir);
		return (cmd_cd_error("cd", tmp));
	}
	//tmp = getcwd(s, 100);
	set_env(env, "OLDPWD", s);
	getcwd(s, 100);
	set_env(env, "PWD", s);
	printf("pwd: %s\n", s);
	free(dir);
	return (EXIT_SUCCESS);
}

char	*cd_nav_to(t_cmd *cmd, t_env *env)
{
	printf("entra nav to\n");
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && !cmd->flags)
		return (expand_environment_variables("$HOME", env));
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0')
			&& ft_strncmp(cmd->flags, "--", 3) == 0)
		return (expand_environment_variables("$HOME", env));
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0')
			&& ft_strncmp(cmd->flags, "-", 2) == 0)
		return (expand_environment_variables("$OLDPWD", env));
	if (!cmd->params || !cmd->params[0])
		return (ft_strdup("NADA"));
	else
		return (ft_strdup(cmd->params[0]));
}

int	cd_nav(char *dir, t_env *env)
{
	printf("%p\n", env);
	printf("dir enter: %s\n", dir);
	if (!(ft_strncmp("$HOME", dir, ft_strlen("$HOME"))))
		return (cmd_error("cd", "HOME not set\n"));
	if (!(ft_strncmp("$OLDPWD", dir, ft_strlen("$OLDPWD"))))
		return (cmd_error("cd", "OLDPWD not set\n"));
	printf("nav to: %s\n", dir);
	cd_go(env, dir);
	//free(dir);
	return (EXIT_SUCCESS);
}

int	ft_cd(t_cmd *cmd, t_env *env)
{
	int	np;

	np = n_flags(cmd->flags);
	if (np < 0)
		return (EXIT_FAILURE);
	if (n_params(cmd->params) > 1 || np > 1)
		return (cmd_error("cd", "too many arguments\n"));
	return (cd_nav(cd_nav_to(cmd, env), env));
}
