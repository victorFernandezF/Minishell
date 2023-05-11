/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:54:54 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 10:56:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * transforming (get/check_env_vars.c)
 * ----------------------------
 *	Take an string with the name of the env var
 *	and returns a new string with its value.
 *
 *	PARAMS:
 *	-> str: string with env var name without '$' (ex: USER)
 *
 * 	RETURN
 *	-> A string with the value of the enviroment var. (ex: victofer)
 */
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

/* 
 * check_env_param (get/check_env_vars.c)
 * ----------------------------
 *	If an enviroment var is found in any parameters, this
 *	function converts it in its value. 
 *	(ex: $USER becomes 'victofer' 
 *
 *	PARAMS:
 *	-> cmd: the struct that contains everything.
 *
 * 	RETURN
 *	-> The struct with the params correctly formatted.
 */
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
		if (is_env_var(cmd->params[i][0]))
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

/* 
 * check_env_input (get/check_env_vars.c)
 * ----------------------------
 *	If a enviroment var is found in any inputs, this
 *	function converts it in its value. 
 *	(ex: $USER becomes 'victofer' 
 *
 *	PARAMS:
 *	-> input: Array of strings with the input filenames.
 *
 * 	RETURN
 *	-> An array of strings with the input filenames correctly
 *		formatted.
 */
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
		if (is_env_var(input[i][0]))
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
