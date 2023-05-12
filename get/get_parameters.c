/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 11:05:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_parameters (get/get_parameters.c)
 * ----------------------------
 *	creates an array of strings with the parameters found
 *	in the command line given by user..
 *
 *	PARAMS:
 *	-> str: command line.
 *
 * 	RETURN
 *	-> An array of strings with every parameters found.
 */
char	**get_parameters(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*param_line;
	char	**param_array;

	j = 0;
	i = skip_cmd_and_flags(str);
	len = strlen_starting_in(str, i);
	param_line = malloc(len * sizeof(char));
	if (!param_line)
		return (NULL);
	while (str[i])
		param_line[j++] = str[i++];
	param_line[j] = '\0';
	param_array = ft_split_2(param_line);
	free(param_line);
	return (param_array);
}
