/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:07:02 by victofer          #+#    #+#             */
/*   Updated: 2023/05/31 19:17:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_between_quotes(char *str, int end)
{
	int	nb_quotes;
	int	i;

	i = -1;
	nb_quotes = 0;
	while (++i < end)
		if (str[i] == 34)
			nb_quotes++;
	if (nb_quotes == 0)
		return (0);
	if (nb_quotes % 2 == 0)
		return (0);
	return (1);
}
