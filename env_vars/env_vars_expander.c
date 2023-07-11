/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/07/11 13:35:21 by victofer         ###   ########.fr       */
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
	char	*no_last_quote;

	i = 0;
	len = ft_strlen(str);
	no_last_quote = malloc(len * sizeof(char));
	if (!no_last_quote)
		return (NULL);
	while (str[i] != '\0' && (str[i] != 34 && str[i] != 39))
	{
		no_last_quote[i] = str[i];
		i++;
	}
	str[i] = '\0';
	return (no_last_quote);
}

/**
 * @brief Converts each environment variable in its value.
 * 
 * @param cmd_line the line with the command.
 * @param envar Struct whith the enviroment vars.
 * @return [Char *] A line with the expanded env vars. 
 */
char	*convert_env_var_in_its_value(char *line, t_env *envar)
{
	char	*env_val;
	char	*env_name;
	int		last_quote;
	char	*str_with_env;
	char	*no_end_quotes;

	last_quote = 0;
	env_name = get_env_var_name_including_dollar(line);
	if (env_var_counter(line) > 1)
	{
		str_with_env = more_than_one_env_vars(line, envar);
		free(env_name);
		return (str_with_env);
	}
	if (!env_name)
		return (NULL);
	if (env_name[ft_strlen(env_name) - 1] == 34
		|| env_name[ft_strlen(env_name) - 1] == 39)
		last_quote = 1;
	no_end_quotes = del_last_quote(env_name);
	env_val = env_var_transformation(env_name, envar);
	str_with_env = fill_str_with_env_value(line, env_name, env_val, last_quote);
	free_env_var_things(no_end_quotes, line, env_name, env_val);
	return (str_with_env);
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

/**
 * @brief Search an environment variable inside the list
 * of evn vars. if env var is found, this function returns
 * its value. if not, returns null.
 * 
 * @param envar list with the environment variables.
 * @param name Name of the variable to search in the list.
 * @return [Char *] Value of the env var. Or Null if not found.
 */
char	*find_env_from_srruct(t_env *envar, char *name)
{
	int		i;
	t_env	*envars;
	t_env	*tmp;

	envars = envar;
	while (envars)
	{
		i = 0;
		if (are_two_strs_equal(envars->var, name))
		{
			if (envars->vals[i + 1] == NULL)
				return (envars->vals[0]);
			while (envars->vals[i])
				i++;
			return (envars->vals[0]);
		}
		tmp = envars->next;
		envars = tmp;
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
	char	**split;
	char	*env_var_value;
	char	*str_with_env_value;

	split = ft_split_2(cmd_line);
	i = -1;
	while (split[++i])
	{
		if (env_var_detector(split[i]))
		{
			if (check_simple_quotes(split[i])
				|| is_inside_simple_quotes(split, i))
			{
				split[i] = replace_simple_quotes_by_double_quotes(split[i]);
				continue ;
			}
			env_var_value = NULL;
			env_var_value = convert_env_var_in_its_value(split[i], envar);
			split[i] = env_var_value;
		}
	}
	str_with_env_value = ft_splitnt(split, 0, 0);
	free_array(split);
	return (replace_simple_quotes_by_double_quotes(str_with_env_value));
}
