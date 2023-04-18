/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:25 by victofer          #+#    #+#             */
/*   Updated: 2023/04/18 18:10:30 by victofer         ###   ########.fr       */
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

static int	*fill_output_pos(int *output_pos, int pos, char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == '>')
			output_pos[pos++] = i;
	}
	return (output_pos);
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
			if (str[i] == '>' && str[i + 1] != '>')
				nb++;
		output_pos = malloc((nb + 1) * sizeof(int));
		if (!output_pos)
			return (NULL);
		output_pos[0] = nb;
		i = -1;
		output_pos = fill_output_pos(output_pos, pos, str, i);
		return (output_pos);
	}
	output_pos = malloc(1 * sizeof(int));
	output_pos[0] = nb;
	return (output_pos);
}
