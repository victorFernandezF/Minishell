/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/01 18:36:41 by victofer         ###   ########.fr       */
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
	temp[i] = '\0';
	env = getenv(temp);
	free(temp);
	if (env == NULL)
		return (env_name);
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
char	*fill_string_redirection(char *redirection, char *env, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*redi;

	len = 0;
	i = -1;
	j = -1;
	while (!is_env_var(redirection[len]))
		len++;
	len += ft_strlen(env);
	if (flag == 1)
		len++;
	redi = malloc((len + 1) * sizeof(char));
	while (!is_env_var(redirection[++i]))
		redi[i] = redirection[i];
	while (env[++j])
		redi[i++] = env[j];
	if (flag == 1)
	{
		redi[i] = 34;
		i++;
	}
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
