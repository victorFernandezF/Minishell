/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/21 19:28:49 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_home(t_env *env);
char	*get_oldpwd(t_env *env);
char	*get_pwd(t_env *env);

int	cd_go(t_cmd *cmd, t_env *env, char *dir)
{
	char	*tmp;
	char	s[100];

	getcwd(s, 100);
	if (chdir(dir) != 0)
	{
		tmp = ft_strjoin(dir, ": No such file or directory");
		return (cmd_cd_error("cd", tmp));
	}
	set_env(env, "OLDPWD", s);
	getcwd(s, 100);
	set_env(env, "PWD", s);
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0')
			&& ft_strncmp(cmd->flags, "-", 2) == 0)
		printf("%s\n", get_pwd(env));
	return (EXIT_SUCCESS);
}

char	*cd_nav_to(t_cmd *cmd, t_env *env)
{
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && !cmd->flags)
		return (get_home(env));
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0')
			&& ft_strncmp(cmd->flags, "--", 3) == 0)
		return (get_home(env));
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0')
			&& ft_strncmp(cmd->flags, "-", 2) == 0)
		return (get_oldpwd(env));
	if (!cmd->params || !cmd->params[0])
		return ("NADA");
	else
		return (cmd->params[0]);
}

int	cd_nav(t_cmd *cmd, char *dir, t_env *env)
{
	if (!(ft_strncmp("$HOME", dir, ft_strlen("$HOME"))))
		return (cmd_error("cd", "HOME not set"));
	if (!(ft_strncmp("$OLDPWD", dir, ft_strlen("$OLDPWD"))))
		return (cmd_error("cd", "OLDPWD not set"));
	cd_go(cmd, env, dir);
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
	return (cd_nav(cmd, cd_nav_to(cmd, env), env));
}
