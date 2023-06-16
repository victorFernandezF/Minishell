/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:56:49 by victofer          #+#    #+#             */
/*   Updated: 2023/06/16 11:57:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if the given string is inside quotes.
 * 
 * @param str string
 * @param end  position where word starts
 * @return 1 if the word is inside quotes. 0 if not.
 */
int	is_between_simple_quotes(char *str, int end)
{
	int	nb_quotes;
	int	i;

	i = -1;
	nb_quotes = 0;
	while (++i < end)
		if (str[i] == 39)
			nb_quotes++;
	if (nb_quotes == 0)
		return (0);
	if (nb_quotes % 2 == 0)
		return (0);
	return (1);
}
