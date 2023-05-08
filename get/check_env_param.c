/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:54:54 by victofer          #+#    #+#             */
/*   Updated: 2023/05/08 12:07:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*transforming(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[++i])
		temp[j++] = str[i];
	temp[j] = '\0';
	return (temp);
}

t_cmd	*check_env_param(t_cmd *cmd)
{
	char	*tmp;
	char	*env;
	char	*tmp_env;
	int		i;

	i = -1;
	while (cmd->params[++i])
	{
		if (cmd->params[i][0] == '#')
		{
			tmp = cmd->params[i];
			free(cmd->params[i]);
			env = transforming(tmp);
			free(env);
			tmp_env = getenv(env);
			cmd->params[i] = tmp_env;
		}
	}
	return (cmd);
}
