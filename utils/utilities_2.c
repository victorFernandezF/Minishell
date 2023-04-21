/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/04/21 12:31:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

/* 
 * skip_whitespaces
 * ----------------------------
 *	Returns an int with the position of the string
 *	after skipping all spaces.
 */
int	skip_whitespaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

/* 
 * skip_whitespaces
 * ----------------------------
 *	Returns an int with the position of the string
 *	after skipping all characters.
 */
int	skip_characters(char *str, int i)
{
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}
