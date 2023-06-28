/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 11:12:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Auxiliary function to help get_param filling the string
 * 
 * @param param 
 * @param cmd_line 
 * @param i 
 * @return A string.
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
 * @brief creates an array of strings with the parameters found
 *	in the command line given by user.
 * 
 * @param cmd_line Command line
 * @return An array of strings with every parameters found. 
 */
char	**get_parameters(char *cmd_line)
{
	int		i;
	int		j;
	int		len;
	char	*param_line;
	char	**param_array;

	j = 0;
	if (ft_strlen(cmd_line) == 0)
		return (NULL);
	i = skip_cmd_and_flags(cmd_line);
	len = strlen_starting_in(cmd_line, i);
	param_line = malloc(len * sizeof(char));
	if (!param_line)
		return (NULL);
	while (cmd_line[i])
		param_line[j++] = cmd_line[i++];
	param_line[j] = '\0';
	param_array = ft_split_minishell(param_line, 0);
	free(param_line);
	return (param_array);
}
