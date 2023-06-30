/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:28:13 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 12:56:31 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_echo(t_cmd *cmd, t_env *env, bool n)
{
	int	i;

	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && n == true)
		set_env(env, "?", "0");
	else if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && n == false)
	{
		ft_putstr_fd("\n", 1);
		set_env(env, "?", "0");
	}
	else
	{
		i = -1;
		while (++i < n_params(cmd->params))
		{
			/*if (!(ft_strncmp("$", cmd->params[i], 1))
				&& ft_strlen(cmd->params[i]) > 1)
				continue ;*/
			ft_putstr_fd(cmd->params[i], 1);
			if (i + 1 < n_params(cmd->params))
				ft_putstr_fd(" ", 1);
		}
		if (n == false)
			ft_putstr_fd("\n", 1);
		set_env(env, "?", "0");
	}
}

int	ft_echo(t_cmd *cmd, t_env *env)
{
	if (cmd->flags)
	{
		if (!(ft_strncmp("-n", cmd->flags, ft_strlen("-n"))))
		{
			print_echo(cmd, env, true);
			return (EXIT_SUCCESS);
		}
		else
			return (cmd_error("echo", "Only -n option allowed\n", env));
	}
	else
	{
		print_echo(cmd, env, false);
		return (EXIT_SUCCESS);
	}
}
