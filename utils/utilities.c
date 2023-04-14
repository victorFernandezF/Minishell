/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/14 12:34:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

int	is_token(char c)
{
	return (c == '|');
}

int	skip_whitespaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	are_there_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
