/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/17 12:20:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	while (redirection[++i] != NULL)
	{
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
