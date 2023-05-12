/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 10:31:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_flags (get/get_flags.c)
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
	int		end;
	char	*flags;

	if (!are_there_char(str, '-'))
		return (NULL);
	start = skip_characters_and_spaces(str, 0);
	end = get_position_of_last_char_found(str, '-');
	end = skip_characters(str, end);
	flags = malloc ((end - start +1) * sizeof(char));
	i = 0;
	if (!flags)
		return (NULL);
	while (start < end)
		flags[i++] = str[start++];
	flags[i] = '\0';
	return (flags);
}
