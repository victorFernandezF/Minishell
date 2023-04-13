/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/13 18:47:33 by victofer         ###   ########.fr       */
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

char	*get_output_from_pos(char *str, int pos)
{
	char	*res;
	int		i;
	int		aux;

	i = 0;
	aux = pos + 1;
	while (str[++pos])
		i++;
	res = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		res[i] = str[aux];
		aux++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	*get_nb_output(char *str)
{
	int	*output_pos;
	int	i;
	int	nb;
	int	pos;

	i = -1;
	nb = 0;
	pos = 1;
	output_pos = NULL;
	if (are_there_char(str, '>'))
	{
		while (str[++i])
			if (str[i] == '>')
				nb++;
		output_pos = malloc((nb + 1) * sizeof(int));
		if (!output_pos)
			return (NULL);
		output_pos[0] = nb;
		i = -1;
		while (str[++i])
			if (str[i] == '>')
				output_pos[pos++] = i;
		return (output_pos);
	}
	output_pos = malloc(1 * sizeof(int));
	output_pos[0] = nb;
	return (output_pos);
}
