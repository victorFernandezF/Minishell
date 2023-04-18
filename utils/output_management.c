/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:25 by victofer          #+#    #+#             */
/*   Updated: 2023/04/18 18:44:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

char	*get_output_from_pos(char *out, char *str, int pos)
{
	int		i;
	int		aux;

	i = 0;
	aux = pos + 1;
	while (str[++pos])
		i++;
	out = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[aux] == ' ')
		aux++;
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		out[i] = str[aux];
		aux++;
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	*get_fd_ftom_outputs(char **output, int nb)
{
	int		i;
	int		j;
	int		*res;

	i = -1;
	j = 0;
	res = malloc((nb + 1) * sizeof(int));
	while (++i < nb)
	{
		if (output[i][0] == '>')
		{
			output[i] = ft_strtrim(output[i], ">");
			res[i] = open(output[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		}
		else
			res[i] = open(output[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	return (res);
}

/* 
 * fill_output_pos
 * ----------------------------
 *	This is an auxiliar function that helps get_nb_output
 *
 *	PARAMS:
 *	-> output_pos: array to fill with positions. 
 *	-> str: A string whith the whole commad (ex: echo -n "hello" > out)
 *
 * 	RETURN
 *	-> output_pos: the given array but with elements.
 */
static int	*fill_output_pos(int *output_pos, char *str)
{
	int	pos;
	int	i;

	pos = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '>')
			output_pos[pos++] = i;
	}
	return (output_pos);
}

/* 
 * get_nb_output
 * ----------------------------
 *	Counts the number of outputs for each command. 
 *
 *	PARAMS:
 *	-> str: A string whith the whole commad (ex: echo -n "hello" > out)
 *
 * 	RETURN
 *	-> An array of ints with following structure 
 *		array[0] = number of outputs
 *		array[1 ...] = positions of each character '>' in str.
 *
 */
int	*get_nb_output(char *str)
{
	int	*output_pos;
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	output_pos = NULL;
	if (are_there_char(str, '>'))
	{
		while (str[++i])
			if (str[i] == '>' && str[i + 1] != '>')
				nb++;
		output_pos = malloc((nb + 1) * sizeof(int));
		if (!output_pos)
			return (NULL);
		output_pos[0] = nb;
		output_pos = fill_output_pos(output_pos, str);
		return (output_pos);
	}
	output_pos = malloc(1 * sizeof(int));
	output_pos[0] = nb;
	return (output_pos);
}
