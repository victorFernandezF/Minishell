/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:53:01 by victofer          #+#    #+#             */
/*   Updated: 2023/07/26 09:59:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Deletes spaces from a string.
 * 
 * @param str string.
 * @return [Char *] A new string with no spaces. 
 */
static char	*delete_spaces(char *str)
{
	int		i;
	int		j;
	int		nb;
	char	*no_spaces;

	i = -1;
	j = 0;
	nb = 0;
	while (str[++i])
		if (str[i] == ' ')
			nb++;
	no_spaces = malloc((ft_strlen(str) - nb) * sizeof(char));
	if (!no_spaces)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			no_spaces[j++] = str[i];
	return (no_spaces);
}

/**
 * @brief Filters an array with all env vars found in
 * cmd line and returns a new array only with the ones
 * that are well formatted.
 * 
 * @param array Array to filter.
 * @return [Char **] Filtered array. 
 */
static char	**take_only_the_good_ones(char **array)
{
	int		i;
	int		j;
	int		len;
	char	**good_envars;

	i = -1;
	len = 0;
	j = 0;
	while (array[++i])
		if (array[i][0] != '$')
			len++;
	if (len == 0)
		return (array);
	good_envars = malloc((len + 1) * sizeof(char *));
	if (!good_envars)
		return (NULL);
	i = -1;
	while (array[++i])
		if (array[i][0] != '$')
			good_envars[j++] = ft_strdup(array[i]);
	good_envars[j] = NULL;
	free_array(array);
	return (good_envars);
}

/**
 * @brief If there are more than one env vars together this
 * function returns a string with evry env vae joined.
 * if one of them is bad formatted or not found, returns only
 * the good one.
 * 
 * @param str String to transform.
 * @param envar List with the env vars.
 * @return [Char *] The string with the values of the env vars.
 */
char	*more_than_one_env_vars(char *str, t_env *envar)
{
	int		i;
	char	*tmp;
	char	*final;
	char	**env;
	char	**temp;

	i = -1;
	env = ft_split(str, '$');
	while (env[++i] != NULL)
	{
		tmp = ft_strjoin("$", env[i]);
		free(env[i]);
		env[i] = convert_env_var_in_its_value(tmp, envar);
	}
	temp = take_only_the_good_ones(env);
	i = get_total_length_of_words_in_array(temp);
	tmp = ft_splitnt(temp, i, 0);
	final = delete_spaces(tmp);
	free_array(temp);
	free(tmp);
	free(str);
	return (final);
}

/**
 * @brief If env var is preceded by some strings (ex: hello$USER).
 * This function joins the first part of the string with the env var
 * value.
 * 
 * @param len Length of the new string.
 * @param env_complete Complete string where env var is
 * @param env List with the env vars.
 * @param flag Flag to control if add quote at the end.
 * @return [char *] String with the result of joinings the
 *  first part of the string with the env var value.
 */
char	*join_firt_str_and_env_var(int len, char *comp, char *env, int flag)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	comp = replace_simple_quotes_by_double_quotes(comp);
	while (!is_env_var(comp[++i]))
		result[i] = comp[i];
	while (env[++j])
		result[i++] = env[j];
	if (flag == 1)
		result[i++] = 34;
	result[i] = '\0';
	return (result);
}

/**
 * @brief Transform a env var in its value if it is not preceded by anything.
 * 
 * @param len Length of the new string.
 * @param env_complete Complete string where env var is
 * @param env List with the env vars.
 * @param flag Flag to control if add quote at the end.
 * @return [char *] String with the env var value.
*/
char	*redi_string_starting(int len, char *env_complete, char *env, int flag)
{
	char	*result;
	int		i;

	i = -1;
	result = malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	env_complete = replace_simple_quotes_by_double_quotes(env_complete);
	while (env[++i])
		result[i] = env[i];
	if (flag == 1)
		result[i++] = 34;
	result[i] = '\0';
	return (result);
}
