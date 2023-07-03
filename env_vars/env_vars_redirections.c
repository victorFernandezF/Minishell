/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:56:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/30 13:29:45 by victofer         ###   ########.fr       */
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
char	*env_var_transformation(char *env_complete, t_env *envar)
{
	int		i;
	int		j;
	char	*temp;
	char	*env;

	i = 0;
	j = 0;
	if (are_two_strs_equal(env_complete, "$PATH"))
	{
		env = get_path(envar);
		return (env);
	}
	temp = malloc((ft_strlen(env_complete) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (env_complete[++i])
		temp[j++] = env_complete[i];
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
 * @param env_complete String with inputs/outputs.
 * @param env String with the value of the env var.
 * @return String with the two strings joined.
 */
char	*fill_string_with_env_var_value(char *env_complete, char *name, char *env, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*redi;
	char	*rest;
	char	*join;

	rest = get_env_rest(env_complete, name);
	len = 0;
	i = -1;
	j = -1;
	while (!is_env_var(env_complete[len]))
		len++;
	len += ft_strlen(env);
	if (flag == 1)
		len++;
	redi = malloc((len + 1) * sizeof(char));
	env_complete = replace_simple_quotes_by_double_quotes(env_complete);
	while (!is_env_var(env_complete[++i]))
		redi[i] = env_complete[i];
	while (env[++j])
		redi[i++] = env[j];
	if (flag == 1)
		redi[i++] = 34;
	redi[i] = '\0';
	if (!rest)
		return (redi);
	join = ft_strjoin(redi, rest);
	free_maximun_of_four_str(rest, redi, NULL, NULL);
	return (join);
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
	int		start;
	int		end;
	char	*tmp;

	j = 0;
	end = 0;
	while (!is_env_var(str[j]))
		j++;
	start = j;
	j++;
	while (str[j] && !is_env_var(str[j]))
	{
		if ((ft_isalpha(str[j]) || str[j] == '_') && str[j] != '\0')
			end++;
		else
			break ;
		j++;
	}
	tmp = ft_substr(str, start, end + 1);
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

char	*get_env_rest(char *complete, char *name)
{
	char	*rest;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (!is_env_var(complete[i]))
		i++;
	while (complete[i] && name[j] && complete[i] == name[j])
	{
		i++;
		j++;
	}
	start = i;
	while (complete[i])
	{
		j++;
		i++;
	}
	i = 0;
	rest = malloc((j + 1) * sizeof(char));
	while (complete[start])
		rest[i++] = complete[start++];
	rest[i++] = '\0';
	return (rest);
}
