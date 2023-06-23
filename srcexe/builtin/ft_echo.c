/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:28:13 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/23 12:42:07 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	print_echo(t_cmd *cmd, t_env *env, bool n)
{
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && n == true)
	{
		set_env(env, "?", "0");
		return (EXIT_SUCCESS);
	}
	return (0);
}

int	ft_echo(t_cmd *cmd, t_env *env)
{
	if (cmd->flags)
	{
		if (!(ft_strncmp("-n", cmd->flags, ft_strlen("-n"))))
		{
			//printf("-n\n");
			return (print_echo(cmd, env, true));
			return (0);
		}
		else
			return (cmd_error("echo", "Only -n option permited\n", env));
	}
	else
	{
		printf("Sin flag\n");
		print_echo(cmd, env, false);
		return (0);
	}
	return (0);
}
