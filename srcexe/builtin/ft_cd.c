/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/13 14:35:38 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	n_params(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	ft_cd_nav(char *dir, t_env *env)
{
	printf("%p\n", env);
	printf("dir enter: %s\n", dir);
	if (!(ft_strncmp("$HOME", dir, ft_strlen("$HOME"))))
		return (cmd_error("cd", "HOME not set\n"));
	if (!(ft_strncmp("$OLDPWD", dir, ft_strlen("$OLDPWD"))))
		return (cmd_error("cd", "OLDPWD not set\n"));

	printf("nav to: %s\n", dir);
	return (EXIT_SUCCESS);
}


int	ft_cd_home(t_cmd *cmd, t_env *env)
{
	char	*dir;

	printf("%p\n", cmd);
	dir = expand_environment_variables("$HOME", env);
	printf("%s\n", dir);
	if (!(ft_strncmp("$HOME", dir, ft_strlen("$HOME"))))
		printf("Sin valor en HOME\n");
	else
	{
		printf("%s\n", dir);
	}
	free(dir);
	return (1);
}

int	ft_cd(t_cmd *cmd, t_env *env)
{
	if (n_params(cmd->params) > 1)
		return (cmd_error("cd", "too many arguments\n"));
	if (!cmd->params || !cmd->params[0]
		|| cmd->params[0][0] == '\0'
		|| ft_strncmp(cmd->params[0], "--", 3) == 0)
		{
		/*printf("%s\n", expand_environment_variables("$HOME", env));
		return (ft_cd_nav(expand_environment_variables("$HOME", env), env));*/
		return (ft_cd_home(cmd, env));
		}
	if (ft_strncmp(cmd->params[0], "-", 2) == 0)
		return (ft_cd_nav(expand_environment_variables("$OLDPWD", env), env));
	return (ft_cd_nav(expand_environment_variables(cmd->params[0], env), env));
}
