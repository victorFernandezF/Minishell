/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:08:41 by victofer          #+#    #+#             */
/*   Updated: 2023/04/17 13:14:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

/* 
 * get_cmd
 * ----------------------------
 *	Splits the name of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the command name.
 */
char	*get_params(char *str)
{
	int		i;
	int		j;
	int		last_flag;
	char	*param;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			last_flag = i;
		}
	}
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	last_flag++;
	param = malloc((i - last_flag) * sizeof(char));
	while (!is_token(str[i]) && !is_redirect(str[last_flag]))
		param[j++] = str[last_flag++];
	param[i] = '\0';
	return (param);
}
