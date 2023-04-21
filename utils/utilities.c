/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/21 12:42:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

/* 
 * are_there_char
 * ----------------------------
 *	Returns 1 if '|' is found in string str.
 *	If not, returns 0.
 */
int	is_pipe(char c)
{
	return (c == '|');
}

/* 
 * is_env_var
 * ----------------------------
 *	Returns 1 if '$' is found in str
 *	If not, returns 0.
 */
int	is_env_var(char c)
{
	return (c == '#');
}

/*
 * is_redirect
 * ----------------------------
 *	Returns 1 if there is some redirect sign or pipe.
 *	If not, returns 0.
 */
int	is_redirect(char c)
{
	return (c == '>' || c == '<');
}

/* 
 * are_there_char
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
