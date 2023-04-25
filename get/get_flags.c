/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/04/25 09:53:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/* 
 * get_flags
 * ----------------------------
 *	Splits the flags of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the flags name.
 */
char	*get_flags(char *str)
{
	int		i;
	int		start;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	i = skip_whitespaces(str, i);
	i = skip_characters(str, i);
	i++;
	if (str[i] != '-')
		return (NULL);
	start = i;
	while (str[++i])
		if (str[i] == ' ' && str[i + 1] != '-')
			break ;
	res = malloc(((i - start) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start < i)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}
