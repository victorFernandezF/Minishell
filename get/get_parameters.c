/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/07/06 19:09:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Auxiliary function to help get_param filling the string
 * 
 * @param param 
 * @param cmd_line 
 * @param i 
 * @return [Char *] A string.
 */
char	*fill_string_param(char *param, char *cmd_line, int i)
{
	int	j;

	j = 0;
	while (cmd_line[++i] != 34)
		param[j++] = cmd_line[i];
	return (param);
}

/**
 * @brief Checks if there is only the cmd name in the line.
 * 
 * @param cmd_line Command line.
 * @return [Int] 1 if only cmd name found. 0 if there are more things.
 */
static int	check_if_only_cmd_name(char *cmd_line)
{
	int	i;

	i = skip_cmd_and_flags(cmd_line);
	if (!cmd_line[i])
		return (1);
	return (0);
}

/**
 * @brief Counts the number of parameters found.
 * 
 * @param param_array 
 * @return [Int] Number of parameters. 
 */
static int	count_parameters(char **param_array)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (param_array[++i])
		len++;
	if (param_array[1][0] == '-')
		len--;
	return (len);
}

/**
 * @brief creates an array of strings with the parameters found
 *	in the command line given by user.
 * 
 * @param cmd_line Command line
 * @return [Char **] An array of strings with every parameters found. 
 */
char	**get_parameters(char *cmd_line)
{
	int		i;
	int		j;
	int		len;
	char	**param;
	char	**param_array;

	i = 0;
	j = 0;
	if (check_if_only_cmd_name(cmd_line))
		return (NULL);
	param_array = ft_split_minishell(cmd_line, 0);
	len = count_parameters(param_array);
	param = malloc((len + 1) * sizeof(char *));
	if (!param)
		return (NULL);
	if (param_array[1][0] == '-')
		i++;
	while (param_array[++i] != NULL)
		param[j++] = param_array[i];
	param[j] = NULL;
	print_array(param);
	free(param_array[0]);
	if (param_array[1][0] == '-')
		free(param_array[1]);
	free(param_array);
	return (param);
}
