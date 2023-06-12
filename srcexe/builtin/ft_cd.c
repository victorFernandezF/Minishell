/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/12 14:17:34 by fortega-         ###   ########.fr       */
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

int	ft_cd_home(t_cmd *cmd, t_env *env)
{
	char	*dir;

	printf("%p\n", cmd);
	dir = expand_environment_variables("$HOME", env);
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
	if (!cmd->params || !cmd->params[0]
		|| cmd->params[0][0] == '\0'
		|| ft_strncmp(cmd->params[0], "--", 3) == 0)
	{
		ft_cd_home(cmd, env);
	}
	return (1);
}
