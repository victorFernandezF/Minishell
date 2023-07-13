/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:26:40 by victofer          #+#    #+#             */
/*   Updated: 2023/07/13 11:48:11 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Joins the first part os original string untill env var char '$'
 *	and the enviroment var value. (str: redir/ env: -R -> redir/-R)
 * 
 * @param env_name String with inputs/outputs.
 * @param env String with the value of the env var.
 * @return [Char *] String with the two strings joined.
 */
static char	*fill_hd_str_with_env_var_value(char *env_name, char *env, int flag)
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
	while (!is_env_var(env_name[++i]))
		redi[i] = env_name[i];
	while (env[++j])
		redi[i++] = env[j];
	if (flag != 0)
		redi[i++] = flag;
	redi[i] = '\0';
	return (redi);
}

/**
 * @brief Converts each environment variable in its value.
 * 
 * @param cmd_line the line with the command.
 * @param envar Struct whith the enviroment vars.
 * @return [Char *] A line with the expanded env vars. 
 */
char	*convert_heredoc_env_var_in_its_value(char *here_line, t_env *envar)
{
	char	*env;
	char	*final;
	char	*no_end_quotes;
	int		add_last_quote;
	char	*env_var_name;

	add_last_quote = 0;
	env_var_name = get_env_var_name_including_dollar(here_line);
	if (!env_var_name)
		return (NULL);
	if (env_var_name[ft_strlen(env_var_name) - 1] == 34
		|| env_var_name[ft_strlen(env_var_name) - 1] == 39)
		add_last_quote = env_var_name[ft_strlen(env_var_name) - 1];
	no_end_quotes = del_last_quote(env_var_name);
	env = env_var_transformation(env_var_name, envar);
	final = fill_hd_str_with_env_var_value(here_line, env, add_last_quote);
	free_maximun_of_four_str(no_end_quotes, here_line, env_var_name, NULL);
	return (final);
}

static char	*get_heredoc_new_line(char *name, char *value)
{
	char	*content;
	int		len;
	int		end;
	int		i;

	i = -1;
	len = ft_strlen(value);
	end = ft_strlen(name) - 1;
	if (name[end] == 39 || name[end] == 34)
		len++;
	content = malloc (len * sizeof(char *));
	while (value[++i])
		content[i] = value[i];
	content[i] = '\0';
	if (name[end] == 39 || name[end] == 34)
	{
		content[i] = 34;
		if (name[end] == 39)
			content[i] = 39;
		content[i + 1] = '\0';
	}
	free(value);
	free(name);
	return (content);
}

/**
 * @brief Expands the environment var found in the command line. 
 * 
 * @param cmd_line line with the command.
 * @return [Char *] The command line with the env vars expanded 
 * 	(their value instead or the var name)
 */
char	*expand_heredoc_env_vars(char *here_line, t_env *envar)
{
	int		i;
	int		len;
	char	*temp;
	char	**array;
	char	*new_line;

	array = ft_split_2(here_line);
	i = -1;
	while (array[++i])
	{
		if (env_var_detector(array[i]))
		{
			new_line = ft_copy_str(array[i]);
			temp = convert_heredoc_env_var_in_its_value(array[i], envar);
			temp = get_heredoc_new_line(new_line, temp);
			array[i] = temp;
		}
	}
	len = get_total_length_of_words_in_array(array);
	len--;
	new_line = ft_splitnt(array, len, 1);
	free_array(array);
	free(here_line);
	return (new_line);
}
