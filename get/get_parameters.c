/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 10:55:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_params_when_output_found (get/get_parameters.c)
 * ----------------------------
 *	Returns a string with every parameters found.
 *	(ex: echo -n hello > output world -> hello world).
 *
 *	PARAMS:
 *	-> str: command line.
 *
 * 	RETURN
 *	-> A string with every parameters found separated by spaces.
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
