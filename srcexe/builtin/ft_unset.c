/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:37:28 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/10 10:08:34 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delvar(char *var, t_env *env)
{
	t_env	*tmp;
	t_env	*del;
	t_env	*prev;

	tmp = env;
	while (tmp && ft_strncmp(tmp->var, var, ft_strlen(tmp->var)) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && prev)
	{
		del = tmp;
		prev->next = tmp->next;
		del->next = NULL;
		freeenv(del);
	}
}

int	ft_unset(t_cmd *cmd, t_env *env)
{
	int	i;

	if (cmd->input)
		close(cmd->input);
	i = -1;
	if (!cmd->params || !cmd->params[0]
		|| cmd->params[0][0] == '\0')
	{
		if (cmd->flags)
			return (cmd_error("unset", "No one option allowed", env));
		else
		{
			set_env(env, "?", "0");
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		while (cmd->params[++i])
			ft_delvar(cmd->params[i], env);
	}
	set_env(env, "?", "0");
	closeback(cmd);
	return (EXIT_SUCCESS);
}
