/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_vars_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 10:56:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * transforming_out (get/check_env_vars_out.c)
 * ----------------------------
 *	Take an string with the name of the env var
 *	and returns a new string with its value but starting with
 *	the character '>' in order to open it correctly in case of '>>'
 *	(ex: $USER -> >victofer)
 *
 *	PARAMS:
 *	-> str: string with env var name without '$' (ex: USER)
 *
 * 	RETURN
 *	-> A string with the value of the enviroment var
 *		starting with '>' (ex: >victofer)
 */
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

/* 
 * check_double_output (get/check_env_vars_out.c)
 * ----------------------------
 *	Take an string with the name of the env var
 *	like this (>$USER) and returns a new string with its value
 *	starting with '>'.
 *
 *	PARAMS:
 *	-> str: string with env var name without '$' (ex: >$USER)
 *
 * 	RETURN
 *	-> A string with the value of the enviroment var.
 *		starting with '>' (ex: >victofer)
 */
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

/* 
 * check_env_output (get/check_env_vars_out.c)
 * ----------------------------
 *	Take an array with the output filenames and transforms any
 *	env var to its value.
 *
 *	PARAMS:
 *	-> output: Array of strings with the outputs.
 *
 * 	RETURN
 *	-> A new array of strings with the ouputs correctly formatted.
  */
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
		if (output[i][0] == '>' && is_env_var(output[i][1]))
			output[i] = check_double_output(output[i]);
		if (output[i][0] != '>' && is_env_var(output[i][1]))
		{
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
