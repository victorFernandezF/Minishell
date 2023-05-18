/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 12:19:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_total_len (env_vars/env_var_line.c)
 * ----------------------------
 *	Calculates the necesary amount of chars to create a
 *	null terminated string with the elements of an array separated by spaces. 
 *
 *	PARAMS:
 *	-> array: An array of strings with the words that will be
 *	joined in the string.
 *
 * 	RETURN
 *	-> Returns the length that the new string must be.
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

/* 
 * convert_env_var_in_its_value (env_vars/env_var_line.c)
 * ----------------------------
 *	This function converts the enviroment var in
 *	in its value. (ex: $USER becomes 'victofer'). 
 *
 *	PARAMS:
 *	-> str: A string that could have a env_var (or not).
 *
 * 	RETURN
 *	-> Returns a string with the env vars transformed.
 */
static char	*convert_env_var_in_its_value(char *str)
{
	char	*tmp;
	char	*env;
	char	*final;

	tmp = get_temporal_redirection(str);
	env = transforming(tmp);
	if (env == NULL)
		print_error_file(tmp, "ambiguous redirect");
	final = fill_string_redirection(str, env);
	free(str);
	str = final;
	free(tmp);
	return (final);
}

/* 
 * spand_all_env_vasr (env_vars/env_var_line.c)
 * ----------------------------
 *	This function spands the enviroment var found
 *	in the command line (ex: $USER becomes 'victofer'). 
 *
 *	PARAMS:
 *	-> str: A string that could have a env_var (or not).
 *
 * 	RETURN
 *	-> Returns a string with the env vars transformed.
 */
char	*spand_all_env_vasr(char *str)
{
	int		i;
	int		len;
	char	*new_line;
	char	**array;
	char	*temp;

	i = -1;
	array = ft_split_2(str);
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
