/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/05/31 18:23:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*del_last_quote(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] != '\0' && str[i] != 34)
	{
		res[i] = str[i];
		i++;
	}
	str[i] = '\0';
	return (res);
}

/**
 * @brief Calculates the necesary amount of chars to create a
 *	null terminated string with the elements of an array separated by spaces.
 * 
 * @param array Array of strings with the words that will be
 *	joined in the string.
 * @return Length that must be the string with every element from the array
 */
static int	get_total_len(char **array)
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

/**
 * @brief Converts the enviroment var in its value.
 * 
 * @param cmd_line the line with the command.
 * @return a line with the spanded env vars. 
 */
static char	*convert_env_var_in_its_value(char *cmd_line)
{
	char	*tmp;
	char	*no_end_quotes;
	int		add_last_quote;
	char	*env;
	char	*final;

	add_last_quote = 0;
	tmp = get_temporal_redirection(cmd_line);
	if (tmp[ft_strlen(tmp) - 1] == 34)
		add_last_quote = 1;
	no_end_quotes = del_last_quote(tmp);
	env = transforming(tmp);
	final = fill_string_redirection(cmd_line, env, add_last_quote);
	free(no_end_quotes);
	free(cmd_line);
	free(tmp);
	return (final);
}

/**
 * @brief Spands the enviroment var found in the command line. 
 * 
 * @param cmd_line line with the command.
 * @return The command line with the env vars spanded 
 * 	(their value instead or the var name)
 */
char	*spand_all_env_vasr(char *cmd_line)
{
	int		i;
	int		len;
	char	*new_line;
	char	**array;
	char	*temp;

	i = -1;
	array = ft_split_2(cmd_line);
	i = -1;
	while (array[++i])
	{
		if (is_there_env_var(array[i]))
		{
			temp = convert_env_var_in_its_value(array[i]);
			array[i] = temp;
		}
	}
	len = get_total_len(array);
	new_line = ft_splitnt(array, len);
	free_array(array);
	return (new_line);
}
