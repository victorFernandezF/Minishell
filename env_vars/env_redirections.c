/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 10:08:35 by victofer         ###   ########.fr       */
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
	if (!temp)
		return (NULL);
	while (str[++i])
		temp[j++] = str[i];
	temp[j] = '\0';
	env = getenv(temp);
	free(temp);
	return (env);
}

/* 
 * fill_string_redirection (env_vars/env_redirections.c)
 * ----------------------------
 *	Joins the first part os original string (till env var char '$')
 *	and the enviroment va value. (str: redir/ env: -R -> redir/-R)
 *
 *	PARAMS:
 *	-> str: String with inputs/outputs.
 *	-> env: String with the value of the env var.
 *
 * 	RETURN
 *	-> A new string with the two strings joined.
*/
char	*fill_string_redirection(char *str, char *env)
{
	int		len;
	int		i;
	int		j;
	char	*redi;

	len = 0;
	while (!is_env_var(str[len]))
		len++;
	len += ft_strlen(env);
	redi = malloc((len + 1) * sizeof(char));
	i = -1;
	while (!is_env_var(str[++i]))
		redi[i] = str[i];
	j = -1;
	while (env[++j])
		redi[i++] = env[j];
	redi[i] = '\0';
	return (redi);
}

/* 
 * get_temporal_redirection (env_vars/env_redirections.c)
 * ----------------------------
 *	Creates a substring with the content of the original string
 *	from the env var character '$' to the end of string.
 *	(ex: redir/$USER -> $USER).	
 *
 *	PARAMS:
 *	-> str: String with the redirection.
 *
 * 	RETURN
 *	-> The substring created.
  */
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
			final = ft_strjoin(redirection[i], env);
			free(redirection[i]);
			redirection[i] = final;
			free(tmp);
		}
	}
	return (redirection);
}
