/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/17 11:10:17 by victofer         ###   ########.fr       */
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
	if (!out)
		return (NULL);
	out[0] = '>';
	while (env[j])
		out[i++] = env[j++];
	out[i] = '\0';
	output = out;
	return (output);
}

char	*fill_string_redirection(char *str, char *env)
{
	int		len;
	int		i;
	int		j;
	char	*out;

	len = 0;
	while (!is_env_var(str[len]))
		len++;
	len += ft_strlen(env);
	out = malloc((len + 1) * sizeof(char));
	i = -1;
	while (!is_env_var(str[++i]))
		out[i] = str[i];
	j = -1;
	while (env[++j])
		out[i++] = env[j];
	out[i] = '\0';
	return (out);
}

char	*get_temporal_redirection(char *str)
{
	int		j;
	char	*tmp;

	j = 0;
	while (!is_env_var(str[j]))
		j++;
	tmp = ft_substr(str, j, ft_strlen(str) - j);
	return (tmp);
}

/* 
 * check_env_redirection (env_vars/env_redirections.c)
 * ----------------------------
 *	Take each redirection files (inputs or outputs) and
 *	transforms each enviroment var in its value.
 *	This function can handle somethin like that (> redir/$USER)
 *	For that, it creates a temporal string splitting the directory part
 *	and the enviroment var part.
 *
 *	PARAMS:
 *	-> output: Array of strings with the inputs/outputs.
 *
 * 	RETURN
 *	-> A new array of strings with the inputs/outputs correctly formatted.
  */
char	**check_env_redirection(char **redirection)
{
	char	*tmp;
	char	*env;
	char	*final;
	int		i;

	i = -1;
	while (redirection[++i])
	{
		if (redirection[i][0] == '>' && is_env_var(redirection[i][1]))
			redirection[i] = check_double_output(redirection[i]);
		if (is_there_env_var(redirection[i]))
		{
			tmp = get_temporal_redirection(redirection[i]);
			env = transforming(tmp);
			if (env == NULL)
				print_error_file(tmp, "ambiguous redirect");
			final = fill_string_redirection(redirection[i], env);
			free(redirection[i]);
			redirection[i] = final;
			free(tmp);
		}
	}
	return (redirection);
}
