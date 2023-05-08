/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:54:54 by victofer          #+#    #+#             */
/*   Updated: 2023/05/08 19:08:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*transforming(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*env;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[++i])
		temp[j++] = str[i];
	temp[j] = '\0';
	env = getenv(temp);
	free(temp);
	return (env);
}

t_cmd	*check_env_param(t_cmd *cmd)
{
	char	*tmp;
	char	*env;
	char	*par;
	int		i;
	int		j;

	i = -1;

	while (cmd->params[++i])
	{
		if (cmd->params[i][0] == '#')
		{
			tmp = cmd->params[i];
			free(cmd->params[i]);
			env = transforming(tmp);
			par = malloc((1 + ft_strlen(env)) * sizeof(char));
			j = -1;
			while (env[++j])
				par[j] = env[j];
			par[j] = '\0';
			cmd->params[i] = par;
		}
	}
	return (cmd);
}

t_cmd	*check_env_cmd(t_cmd *cmd)
{
	char	*tmp;
	char	*env;
	char	*name;
	int		i;
	int		j;

	i = -1;

	if (cmd->cmd[0] == '#')
	{
		tmp = cmd->cmd;
		free(cmd->cmd);
		env = transforming(tmp);
		name = malloc((1 + ft_strlen(env)) * sizeof(char));
		j = -1;
		while (env[++j])
			name[j] = env[j];
		name[j] = '\0';
		cmd->cmd = name;
	}
	return (cmd);
}

char	**check_env_input(char **input)
{
	char	*tmp;
	char	*env;
	char	*in;
	int		i;
	int		j;

	i = -1;
	while (input[++i])
	{
		if (input[i][0] == '#')
		{
			tmp = input[i];
			free(input[i]);
			env = transforming(tmp);
			in = malloc((1 + ft_strlen(env)) * sizeof(char));
			j = -1;
			while (env[++j])
				in[j] = env[j];
			in[j] = '\0';
			input[i] = in;
		}
	}
	return (input);
}
