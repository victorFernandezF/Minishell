/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 11:00:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * are_there_char (utils/utilities.c)
 * ----------------------------
 *	Returns 1 if '|' is found in string str.
 *	If not, returns 0.
 */
int	is_pipe(char c)
{
	return (c == '|');
}

/* 
 * is_env_var (utils/utilities.c)
 * ----------------------------
 *	Returns 1 if '$' is found in str
 *	If not, returns 0.
 */
int	is_env_var(char c)
{
	return (c == '#');
}

/*
 * is_redirect (utils/utilities.c)
 * ----------------------------
 *	Returns 1 if there is some redirect sign or pipe.
 *	If not, returns 0.
 */
int	is_redirect(char c)
{
	return (c == '>' || c == '<');
}

/* 
 * are_there_char (utils/utilities.c)
 * ----------------------------
 *	Returns 1 if char c is found in string str.
 *	If not, returns 0.
 */
int	are_there_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

/* 
 * print_error_file (utils/utilities.c)
 * ----------------------------
 *	This function prints an error when trying to open
 *	a file that does not exist. 
 *
 *	PARAMS:
 *	-> input: The filename. 
 *	-> msg: The message that will be displayed.
 *	-> cmd:	The command structure.
 */
void	print_error_file(char *input, char *msg)
{
	printf("%s: %s\n", input, msg);
}
