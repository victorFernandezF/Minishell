/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:53:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/27 18:24:40 by victofer         ###   ########.fr       */
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
	int		nb;
	int		i;
	int		j;
	char	*nosp;

	i = -1;
	j = 0;
	nb = 0;
	while (str[++i])
		if (str[i] == ' ')
			nb++;
	nosp = malloc((ft_strlen(str) - nb) * sizeof(char));
	if (!nosp)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			nosp[j++] = str[i];
	return (nosp);
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
	char	**res;

	i = -1;
	len = 0;
	j = 0;
	while (array[++i])
		if (array[i][0] != '$')
			len++;
	if (len == 0)
		return (array);
	res = malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (array[++i])
		if (array[i][0] != '$')
			res[j++] = ft_copy_str(array[i]);
	res[j] = NULL;
	free_array(array);
	return (res);
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
	tmp = ft_splitnt(temp, i);
	final = delete_spaces(tmp);
	free_array(temp);
	free(tmp);
	free(str);
	return (final);
}

/**
 * @brief Counts every env vars sign '$' in the string-
 * 
 * @param str String (command line).
 * @return [Int] The number of '$' found.
 */
int	env_var_counter(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while(str[++i])
		if (is_env_var(str[i]))
			res++;
	return (res);
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
char	*join_firts_part_str_and_env_var(int len, char *env_complete, char *env, int flag)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	env_complete = replace_simple_quotes_by_double_quotes(env_complete);
	while (!is_env_var(env_complete[++i]))
		result[i] = env_complete[i];
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