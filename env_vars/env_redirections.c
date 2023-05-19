/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 12:32:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Take an string with the name of the env var
 *	and returns a new string with its value.
 * 
 * @param str String with env var name starrting with '$'
 * @return String with the enviroment var value.
 */
char	*transforming(char *env_name)
{
	int		i;
	int		j;
	char	*temp;
	char	*env;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(env_name) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (env_name[++i])
		temp[j++] = env_name[i];
	temp[j] = '\0';
	env = getenv(temp);
	free(temp);
	return (env);
}

/**
 * @brief Joins the first part os original string untill env var char '$'
 *	and the enviroment var value. (str: redir/ env: -R -> redir/-R)
 * 
 * @param redirection String with inputs/outputs.
 * @param env String with the value of the env var.
 * @return String with the two strings joined.
 */
char	*fill_string_redirection(char *redirection, char *env)
{
	int		len;
	int		i;
	int		j;
	char	*redi;

	len = 0;
	if (env == NULL)
		print_error_file(redirection, "ambiguous redirect");
	while (!is_env_var(redirection[len]))
		len++;
	len += ft_strlen(env);
	redi = malloc((len + 1) * sizeof(char));
	i = -1;
	while (!is_env_var(redirection[++i]))
		redi[i] = redirection[i];
	j = -1;
	while (env[++j])
		redi[i++] = env[j];
	redi[i] = '\0';
	return (redi);
}

/**
 * @brief Creates a substring with the content of the original 
 * 	string from the env var character '$' to the end of string.
 * 
 * @param redirection String with the redirection.
 * @return The substring created. 
 */
char	*get_temporal_redirection(char *redirection)
{
	int		j;
	char	*tmp;

	j = 0;
	while (!is_env_var(redirection[j]))
		j++;
	tmp = ft_substr(redirection, j, ft_strlen(redirection) - j);
	return (tmp);
}

/**
 * @brief Take each redirection files (inputs or outputs) and
 *	transforms each enviroment var in its value.
 *	This function can handle somethin like that (> redir/$USER)
 *	For that, it creates a temporal string splitting the directory part
 *	and the enviroment var part.
 * 
 * @param redirection Array of strings with the inputs/outputs.
 * @return Array of strings with the inputs/outputs correctly formatted. 
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
