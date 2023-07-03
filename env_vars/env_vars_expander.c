/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/06/30 13:48:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Delete the last quote of the env var.
 * 
 * @param str 
 * @return [Char *] The given string without the last quote. 
 */
char	*del_last_quote(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] != '\0' && (str[i] != 34 && str[i] != 39))
	{
		res[i] = str[i];
		i++;
	}
	str[i] = '\0';
	return (res);
}

/**
 * @brief Converts each environment variable in its value.
 * 
 * @param cmd_line the line with the command.
 * @param envar Struct whith the enviroment vars.
 * @return [Char *] A line with the expanded env vars. 
 */
char	*convert_env_var_in_its_value(char *cmd_line, t_env *envar)
{
	char	*env_var_name;
	char	*no_end_quotes;
	int		add_last_quote;
	char	*env;
	char	*final;

	add_last_quote = 0;
	env_var_name = get_env_var_name_including_dollar(cmd_line);
 	if (env_var_counter(cmd_line) > 1)
	{
		final = more_than_one_env_vars(cmd_line, envar);
		free(env_var_name);
		return (final);
	}
	if (!env_var_name)
		return (NULL);
	if (env_var_name[ft_strlen(env_var_name) - 1] == 34
		|| env_var_name[ft_strlen(env_var_name) - 1] == 39)
		add_last_quote = 1;
	no_end_quotes = del_last_quote(env_var_name);
	env = env_var_transformation(env_var_name, envar);
	final = fill_string_with_env_var_value(cmd_line, env_var_name, env, add_last_quote);
	free_env_var_things(no_end_quotes, cmd_line, env_var_name, env);
	return (final);
}

/**
 * @brief Replaces every simple quote (ascii: 39) found in string
 *  by double quotes (ascii 34) which are managed by ft_split_minishell
 *  in future functions
 * 
 * @param str String.
 * @return [Char *] The given string with quotes replaced. 
 */
char	*replace_simple_quotes_by_double_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 39)
			str[i] = 34;
	return (str);
}

char	*find_env_from_srruct(t_env *envar, char *name)
{
	int		i;
	t_env	*vari;
	t_env	*tmp;

	vari = envar;
	while (vari)
	{
		i = 0;
		if (are_two_strs_equal(vari->var, name))
		{
			if (vari->vals[i + 1] == NULL)
				return (vari->vals[0]);
			while (vari->vals[i])
				i++;
			return (vari->vals[0]);
		}
		tmp = vari->next;
		vari = tmp;
	}
	return (NULL);
}

/**
 * @brief Expands the environment var found in the command line. 
 * 
 * @param cmd_line line with the command.
 * @return [Char *] The command line with the env vars expanded 
 * 	(their value instead or the var name)
 */
char	*expand_environment_variables(char *cmd_line, t_env *envar)
{
	int		i;
	int		len;
	char	*new_line;
	char	**array;
	char	*temp;

	array = ft_split_2(cmd_line);
	i = -1;
	while (array[++i])
	{
		if (env_var_detector(array[i]))
		{
			if (check_simple_quotes(array[i])
				|| is_inside_simple_quotes(array, i))
				continue ;
			temp = NULL;
			temp = convert_env_var_in_its_value(array[i], envar);
			array[i] = temp;
		}
	}
	len = get_total_length_of_words_in_array(array);
	new_line = ft_splitnt(array, len);
	free_array(array);
	return (replace_simple_quotes_by_double_quotes(new_line));
}
