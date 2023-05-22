/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/05/22 11:47:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	i = skip_cmd_and_flags(cmd_line);
	len = strlen_starting_in(cmd_line, i);
	param_line = malloc(len * sizeof(char));
	if (!param_line)
		return (NULL);
	while (cmd_line[i])
	{
		if (is_env_var(cmd_line[i]))
			i = skip_characters(cmd_line, i);
		else
		param_line[j++] = cmd_line[i++];
	}
	param_line[j] = '\0';
	param_array = ft_split_2(param_line);
	free(param_line);
	return (param_array);
}
