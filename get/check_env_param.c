/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:54:54 by victofer          #+#    #+#             */
/*   Updated: 2023/05/08 18:27:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*transforming(char *str)
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

static char	*transforming_out(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*env;

	i = 1;
	j = 0;
	temp = malloc(ft_strlen(str) * sizeof(char));
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

static char	*check_double_output(char *output)
{
	char	*tmp;
	char	*env;
	char	*out;
	int		i;
	int		j;

	tmp = output;
	free(output);
	j = 0;
	i = 1;
	env = transforming_out(tmp);
	out = malloc((2 + ft_strlen(env)) * sizeof(char));
	out[0] = '>';
	while (env[j])
		out[i++] = env[j++];
	out[i] = '\0';
	output = out;
	return (output);
}

char	**check_env_output(char **output)
{
	char	*tmp;
	char	*env;
	char	*out;
	int		i;
	int		j;

	i = -1;
	while (output[++i])
	{
		printf("%s\n", output[i]);
		if (output[i][0] == '>' && output[i][1] == '#')
			output[i] = check_double_output(output[i]);
		if (output[i][0] != '>' && output[i][0] == '#')
		{
			printf("JELOU MAI FREN\n");
			tmp = output[i];
			free(output[i]);
			env = transforming(tmp);
			out = malloc((1 + ft_strlen(env)) * sizeof(char));
			j = -1;
			while (env[++j])
				out[j] = env[j];
			out[j] = '\0';
			output[i] = out;
		}
	}
	return (output);
}
