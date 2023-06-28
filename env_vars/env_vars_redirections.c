/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 10:37:45 by victofer         ###   ########.fr       */
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
char	*env_var_transformation(char *env_name, t_env *envar)
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
	env = find_env_from_srruct(envar, temp);
	free(temp);
	if (env == NULL)
		env = " ";
	return (env);
}

/**
 * @brief Joins the first part os original string untill env var char '$'
 *	and the enviroment var value. (str: redir/ env: -R -> redir/-R)
 * 
 * @param env_name String with inputs/outputs.
 * @param env String with the value of the env var.
 * @return String with the two strings joined.
 */
char	*fill_string_with_env_var_value(char *env_name, char *env, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*redi;

	len = 0;
	i = -1;
	j = -1;
	while (!is_env_var(env_name[len]))
		len++;
	len += ft_strlen(env);
	if (flag == 1)
		len++;
	redi = malloc((len + 1) * sizeof(char));
	env_name = replace_simple_quotes_by_double_quotes(env_name);
	while (!is_env_var(env_name[++i]))
		redi[i] = env_name[i];
	while (env[++j])
		redi[i++] = env[j];
	if (flag == 1)
		redi[i++] = 34;
	redi[i] = '\0';
	return (redi);
}

/**
 * @brief Creates a substring with the content of the original 
 * 	string from the env var character '$' to the end of string.
 * 
 * @param str String with the str.
 * @return The substring created. 
 */
char	*get_env_var_name_including_dollar(char *str)
{
	int		j;
	char	*tmp;

	j = 0;
	while (!is_env_var(str[j]))
		j++;
	tmp = ft_substr(str, j, ft_strlen(str) - j);
	return (tmp);
}

/**
 * @brief Calculates the necesary amount of chars to create a
 *	null terminated string with the elements of an array separated by spaces.
 * 
 * @param array Array of strings with the words that will be
 *	joined in the string.
 * @return The length of the future string with every element from the array
 */
int	get_total_length_of_words_in_array(char **array)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			len++;
	}
	len += i;
	return (len);
}
