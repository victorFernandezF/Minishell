/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 10:07:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Returns 1 if '|' is found in string str.
 *	If not, returns 0.
 * 
 * @param c char
 * @return int 0 or 1. 
 */
int	is_pipe(char c)
{
	return (c == '|');
}

/**
 * @brief Returns 1 if '$' is found in str
 *	If not, returns 0.
 * 
 * @param c char.
 * @return int 0 or 1.
 */
int	is_env_var(char c)
{
	return (c == '#');
}

/**
 * @brief Returns 1 if there is some redirect sign or pipe.
 *	If not, returns 0.
 * 
 * @param c char.
 * @return int 0 or 1.
 */
int	is_redirect(char c)
{
	return (c == '>' || c == '<');
}

/**
 * @brief Returns 1 if char c is found in string str.
 *	If not, returns 0.
 * 
 * @param str line.
 * @param c character to search.
 * @return int 0 or 1.
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

/**
 * @brief Prints an error mesage and exit the program.
 * 
 * @param name name of the error.
 * @param msg message to display before exit.
 */
void	print_error_file(char *name, char *msg)
{
	printf("%s: %s\n", name, msg);
	exit(-1);
}
