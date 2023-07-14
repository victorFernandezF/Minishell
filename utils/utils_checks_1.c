/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/07/14 14:07:37 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Returns 1 if '|' is found in string str.
 *	If not, returns 0.
 * 
 * @param c char
 * @return [Int] 1 if '|' is found in string. 0 if not.
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
 * @return [Int] 1 if '$' is found. 0 if not.
 */
int	is_env_var(char c)
{
	return (c == '$');
}

/**
 * @brief Returns 1 if there is some redirect sign or pipe.
 *	If not, returns 0.
 * 
 * @param c char.
 * @return [Int] 0 or 1.
 */
int	is_redirect(char c)
{
	return (c == '>' || c == '<');
}

/**
 * @brief Checks if a character is an space.
 * 
 * @param c character to check
 * @return [Int] 1 if c is a space, 0 if not. 
 */
int	is_space_minishel(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/**
 * @brief Returns 1 if detects any environment variable sign($) in the string. 
 * 
 * @param str String
 * @return [Int] 1 if an env var is found. If not 0.
 */
int	env_var_detector(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_env_var(str[i]) && ft_isalpha(str[i + 1]))
			return (1);
	return (0);
}
